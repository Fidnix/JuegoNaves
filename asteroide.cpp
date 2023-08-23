#include "asteroide.hpp"

using namespace std;

void asteroides::pintar(){
    gotoxy(x,y); cout <<((char) 184);
}

void asteroides::mover(){
    gotoxy(x,y); cout << " ";
    y++;
    if(y>=25){
        x = rand()%71+3;
        y = 4;
    }
    gotoxy(x,y);cout << ((char) 184);
}

void asteroides::choque(struct ship &reference_Ship){
    if(x >= reference_Ship.return_X() && x < reference_Ship.return_X() + 5 && y >= reference_Ship.return_Y() && y < reference_Ship.return_Y() +2){
        reference_Ship.perder_salud();
        reference_Ship.pintar_corazones();

        x=rand()%71+3;
        y=4;
    }
}