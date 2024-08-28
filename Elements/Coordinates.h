//
// Created by cachi on 27/08/2024.
//

#ifndef SANDGOBRRRDOWN_COORDINATES_H
#define SANDGOBRRRDOWN_COORDINATES_H


class Coordinates {
private:
    int x, y;
public:
    Coordinates(int _x, int _y): x(_x), y(_y){};
    
    [[nodiscard]] int getX() const{ return x; }
    [[nodiscard]] int getY() const{ return y; }
    
    void setX(int _x){ x = _x; }
    void setY(int _y){ y= _y;};
    
    [[nodiscard]] Coordinates * bottom() { return new Coordinates(x, y+1); }
    [[nodiscard]] Coordinates * left(){ return new Coordinates(x-1, y); }
    [[nodiscard]] Coordinates * right(){ return new Coordinates(x+1, y); }
    [[nodiscard]] Coordinates * top(){ return new Coordinates(x, y-1); }
    [[nodiscard]] Coordinates * bottomLeft() { return new Coordinates(x-1, y+1); }
    [[nodiscard]] Coordinates * bottomRight() { return new Coordinates(x+1, y+1); }
    [[nodiscard]] Coordinates * topLeft(){ return new Coordinates(x-1, y-1); }
    [[nodiscard]] Coordinates * topRight(){ return new Coordinates(x+1, y-1); }
};


#endif //SANDGOBRRRDOWN_COORDINATES_H
