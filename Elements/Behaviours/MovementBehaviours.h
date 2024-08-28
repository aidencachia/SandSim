//
// Created by cachi on 26/08/2024.
//

#ifndef SANDGOBRRRDOWN_MOVEMENTBEHAVIOURS_H
#define SANDGOBRRRDOWN_MOVEMENTBEHAVIOURS_H

#include "../Element.h"
class Element;

class MovementBehaviour{
private:
    bool justCreated;
    void virtual move(Element *){};
public:
    MovementBehaviour(): justCreated(true){};
    void exec(Element* element){if(!justCreated) move(element); else justCreated = false;};
//    virtual std::string name(){return "BaseMovementBehaviour";}
};

class LiquidMovementBehaviour: public MovementBehaviour{
private:
    void move(Element*) override;
public:
//    std::string name() override {return "LiquidMovementBehaviour";}
};

class SandMovementBehaviour: public MovementBehaviour{
private:
    void move(Element*) override;
public:
//    std::string name() override {return "SandMovementBehaviour";}
};

class BlankMovementBehaviour: public MovementBehaviour{
private:
    void move(Element*) override {};
public:
//    std::string name() override {return "BlankMovementBehaviour";}
};
#endif //SANDGOBRRRDOWN_MOVEMENTBEHAVIOURS_H
