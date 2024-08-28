//
// Created by cachi on 26/08/2024.
//

#ifndef SANDGOBRRRDOWN_ELEMENT_H
#define SANDGOBRRRDOWN_ELEMENT_H

#include <iostream>
#include "Behaviours/MovementBehaviours.h"
#include "Coordinates.h"
#include "Behaviours/DisplayBehaviours.h"

class Element{
private:
    Coordinates * coordinates{};
    MovementBehaviour* movementBehaviour{};
    DisplayBehaviour* displayBehaviour{};
    double density{};
public:
    Element();
    Element(Coordinates*, MovementBehaviour*, DisplayBehaviour*, double _density);
    Element(Element* gameElement, Coordinates*);
    
    Coordinates * getCoordinates() { return coordinates; }
    void setCoordinates(Coordinates* _coordinates) { coordinates = _coordinates; }
    
    double getDensity(){ return density; }
    void setDensity(double _density) {density = _density; }
    
    MovementBehaviour * getMovementBehaviour(){ return movementBehaviour; }
    void setMovementBehaviour(MovementBehaviour * _movementBehaviour){ movementBehaviour = _movementBehaviour; }
    
    DisplayBehaviour * getDisplayBehaviour(){ return displayBehaviour; }
    void setDisplayBehaviour(DisplayBehaviour * _displayBehaviour){ displayBehaviour = _displayBehaviour; }
    
    void gameElementFunction(){ movementBehaviour->exec(this); }
    void swapWith(Coordinates*);
    void swapWith(Element*);
    void display() {displayBehaviour->exec();};
};

void swapElements(Element**, Coordinates coordinates1, Coordinates coordinates2);

// Water Element

class ElementFactory{
    public:
        static Element * getNewWater(Coordinates* coordinates){ return new Element(coordinates, new LiquidMovementBehaviour, new WaterDisplayBehaviour, 5); }
        static Element * getNewAir(Coordinates* coordinates){ return new Element(coordinates, new BlankMovementBehaviour, new AirDisplayBehaviour, -20); }
        static Element * getNewSand(Coordinates* coordinates){ return new Element(coordinates, new SandMovementBehaviour, new SandDisplayBehaviour, 10); }
};
#endif //SANDGOBRRRDOWN_ELEMENT_H
