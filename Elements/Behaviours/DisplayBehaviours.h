//
// Created by cachi on 27/08/2024.
//

#ifndef SANDGOBRRRDOWN_DISPLAYBEHAVIOURS_H
#define SANDGOBRRRDOWN_DISPLAYBEHAVIOURS_H


#include <iostream>

class DisplayBehaviour {
public:
    virtual void exec(){};
    virtual std::string name(){return "BaseDisplayBehaviour";}
};

class WaterDisplayBehaviour: public DisplayBehaviour{
public:
    void exec() override { std::cout << "W"; }
    std::string name() override {return "WaterDisplayBehaviour";}
};

class SandDisplayBehaviour: public DisplayBehaviour{
public:
    void exec() override { std::cout << "S"; }
    std::string name() override {return "SandDisplayBehaviour";}
};

class AirDisplayBehaviour: public DisplayBehaviour{
public:
    void exec() override { std::cout << " "; }
    std::string name() override {return "AirDisplayBehaviour";}
};


#endif //SANDGOBRRRDOWN_DISPLAYBEHAVIOURS_H
