//
// Created by cachi on 26/08/2024.
//

#ifndef SANDGOBRRRDOWN_GAME_H
#define SANDGOBRRRDOWN_GAME_H

#include "Elements/Element.h"
#include <thread>
#include <mutex>
#include <unistd.h>

class Game {
private:
    Element **gameField;
    static Game * singletonGame;
    static int rows, columns;
    std::mutex update_mutex;
    
    Game(int _rows, int _columns);
    
    ~Game() {
        delete[] gameField[0];  // Delete the contiguous block of memory
        delete[] gameField;  // Delete the row pointers
    }
public:
    static Game * getGame(){return singletonGame;};
    static Game * getGame(int rows, int columns);
    
    static Element * getElementAt(Coordinates * coordinates){ return coordinates->getX() >= columns || coordinates->getY() >= rows ?
                                                                     nullptr : &getGame()->gameField[coordinates->getY()][coordinates->getX()]; }
    
    void newWater(Coordinates * coordinates){ gameField[rows-1-coordinates->getY()][coordinates->getX()] = *ElementFactory::getNewWater(coordinates); }
    void newSand(Coordinates * coordinates){ gameField[rows-1-coordinates->getY()][coordinates->getX()] = *ElementFactory::getNewSand(coordinates); }
    void newAir(Coordinates * coordinates){ gameField[rows-1-coordinates->getY()][coordinates->getX()] = *ElementFactory::getNewAir(coordinates); }
    
    void run();
    void runTick();
    void display();
    void user();
    
    static void start(int rows, int columns);
};


#endif //SANDGOBRRRDOWN_GAME_H
