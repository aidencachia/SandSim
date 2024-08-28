//
// Created by cachi on 26/08/2024.
//

#include <mutex>
#include <thread>
#include "Game.h"
int Game::columns = 0, Game::rows = 0;
Game * Game::singletonGame = nullptr;

Game::Game(int _rows, int _columns) {
    rows = _rows;
    columns = _columns;
    
    // Allocate memory for a 2D array as a contiguous block
    gameField = new Element*[rows];
    gameField[0] = new Element[rows * columns];  // Allocate all at once
    
    for (int x = 1; x < rows; ++x) {
        gameField[x] = gameField[0] + x * columns;  // Set row pointers to appropriate locations
    }
    
    // Initialize the elements
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < columns; ++x) {
            gameField[y][x] = *ElementFactory::getNewAir(new Coordinates(x, y));  // Assign AirElement directly
        }
    }
}

Game * Game::getGame(int rows, int columns) {
    if (singletonGame == nullptr){
        Game::rows = rows;
        Game::columns = columns;
        singletonGame = new Game(rows, columns);
    }
    return getGame();
}

void Game::runTick() {
    for(int y = rows - 1; y >= 0; --y){
        for(int x = columns - 1; x >= 0; --x){
            gameField[y][x].gameElementFunction();
        }
    }
}

void Game::display() {
    for(int y = 0; y < rows; ++y){
        for(int x = 0; x < columns; ++x){
            gameField[y][x].display();
        }
        std::cout<<std::endl;
    }
}

void Game::run(){
    do {
        update_mutex.lock();
        runTick();
        update_mutex.unlock();
        display();
        std::cout<<"----------+"<<std::endl;
        sleep(1);
    } while (true);
}

void Game::user(){
    bool stop = false;
    do{
        char option;
        std::cin >> option;
        
        update_mutex.lock();
        Coordinates coordinates(5,2);
        switch (option) {
            case 's':
            case 'S':
                Game::getGame()->newSand(&coordinates);
                break;
            case 'w':
            case 'W':
                Game::getGame()->newWater(&coordinates);
                break;
            case 'e':
                stop = true;
        }
        
        update_mutex.unlock();
    } while (!stop);
}

void Game::start(int rows, int columns) {
    Game * game = Game::getGame(rows, columns);
    
    std::thread gameThread{&Game::run, game};
    std::thread userThread{&Game::user, game};
    
    gameThread.join();
    userThread.join();
}