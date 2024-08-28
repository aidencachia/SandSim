//
// Created by cachi on 26/08/2024.
//
#include <random>

#include "../Element.h"
#include "MovementBehaviours.h"
#include "../../Game.h"

// Liquid Function
void LiquidMovementBehaviour::move(Element* element){
    Element* down = Game::getElementAt(element->getCoordinates()->bottom());
    bool downFree = down != nullptr && down->getDensity() < element->getDensity();

    if (downFree){
        element->swapWith(down);
    } else {
        Element * left = Game::getElementAt(element->getCoordinates()->left());
        Element * right = Game::getElementAt(element->getCoordinates()->right());

        bool leftFree = left != nullptr && left->getDensity()<element->getDensity();
        bool rightFree = right != nullptr && right->getDensity()<element->getDensity();

        if(leftFree && rightFree){
            // TODO Random Implementation here not necessary, tree like check for free elements
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_int_distribution<int> dist(false,true);

            if(dist(mt))
                leftFree = false;
            else
                rightFree = false;
        }
        if(leftFree)
            element->swapWith(left);
        else if (rightFree)
            element->swapWith(right);
    }
}

// Sand Function
void SandMovementBehaviour::move(Element* element){
    Coordinates* downCoords = element->getCoordinates()->bottom();
    Element* down = Game::getElementAt(downCoords);
    bool downFree = down != nullptr && down->getDensity() < element->getDensity();

    if (downFree){
        element->swapWith(down);
    } else {
        Element * left = Game::getElementAt(element->getCoordinates()->bottomLeft());
        Element * right = Game::getElementAt(element->getCoordinates()->bottomRight());

        bool leftFree = left != nullptr && left->getDensity()<element->getDensity();
        bool rightFree = right != nullptr && right->getDensity()<element->getDensity();

        if(leftFree && rightFree){
            // TODO Random Implementation here not necessary, tree like check for free elements
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_int_distribution<int> dist(false,true);

            if(dist(mt))
                leftFree = false;
            else
                rightFree = false;
        }
        if(leftFree)
            element->swapWith(left);
        else if (rightFree)
            element->swapWith(right);
    }
}
