#ifndef BALA_H
#define BALA_H

#include <iostream>
#include "render.hpp"

class bala{
    int x,y;
    public:
        bala(int _x, int _y):x(_x), y(_y){}
        int return_x(){return x;}
        int return_y(){return y;}
        void mover();
        bool fuera();
};

#endif