#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include "render.hpp"

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

class ship{
    int x, y, corazones, vidas;
public:
    ship(int _x, int _y, int _corazones, int _vidas): x(_x), y(_y), corazones(_corazones), vidas(_vidas){}
    // ship(int x, int y, int corazones);
    void pintar();
    void borrar();
    void mover(char tecla);
    void pintar_corazones();
    void perder_salud();
    void animacion_morir();

    int return_X(){return x;}
    int return_Y(){return y;}
    int return_hearts(){return vidas;}

    void Cor(){corazones--;}
};

#endif