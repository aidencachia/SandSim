//
// Created by cachi on 26/08/2024.
//

#include <cstring>
#include "Element.h"
#include "Behaviours/MovementBehaviours.h"
#include "../Game.h"

Element::Element()= default;

Element::Element(Coordinates* _coordinates, MovementBehaviour* _movementBehaviour, DisplayBehaviour* _displayBehaviour, double _density){
    coordinates = _coordinates;
    movementBehaviour = _movementBehaviour;
    displayBehaviour = _displayBehaviour;
    density = _density;
}

Element::Element(Element* gameElement, Coordinates* _coordinates){
    movementBehaviour = gameElement->movementBehaviour;
    displayBehaviour = gameElement->displayBehaviour;
    density = gameElement->density;
    coordinates = _coordinates;
}

void swapElements(Coordinates* coordinates1, Coordinates* coordinates2){
    Element* element1 = Game::getElementAt(coordinates1);
    Element* element2 = Game::getElementAt(coordinates2);
    
    double tempDensity = element1->getDensity();
    DisplayBehaviour * tempDisplayBehaviour = element1->getDisplayBehaviour();
    MovementBehaviour * tempMovementBehaviour = element1->getMovementBehaviour();
    
    element1->setDensity(element2->getDensity());
    element1->setDisplayBehaviour(element2->getDisplayBehaviour());
    element1->setMovementBehaviour(element2->getMovementBehaviour());
    
    element2->setDensity(tempDensity);
    element2->setDisplayBehaviour(tempDisplayBehaviour);
    element2->setMovementBehaviour(tempMovementBehaviour);
}

void Element::swapWith(Coordinates* _coordinates) {
    swapElements(coordinates, _coordinates);
}

void Element::swapWith(Element* element) {
    swapWith(element->coordinates);
}

Element ** getRelativeGameField(Element** gameField, int x, int y, int size){
    if(size %2 == 1)
        return nullptr;
    return &(&gameField[x-size/2])[y-size/2];
}
