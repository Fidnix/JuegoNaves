#include "bala.hpp"

using namespace std;

void bala::mover(){
    gotoxy(x,y); cout << " ";
    if(y>4) y--;
    gotoxy(x,y); cout << "*";
}

bool bala::fuera(){
    if(y<=4)
        return true;
    return false;
}