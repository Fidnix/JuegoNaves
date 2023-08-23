#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include <iostream>
#include "render.hpp"
#include "ship.hpp"

class asteroides{
    int x,y;
public:
    asteroides(int _x, int _y): x(_x), y(_y){}
    void pintar();
    void mover();
    void choque(struct ship &x);
    int return_x(){return x;}
    int return_y(){return y;}
};

#endif