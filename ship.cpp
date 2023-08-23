#include "ship.hpp"

using namespace std;

void ship::pintar(){
    gotoxy(x,y); cout << "  " << ((char) 30) << "  ";
    gotoxy(x,y+1); cout << " " << ((char) 40) << ((char) 207) << ((char) 41) << " ";
    gotoxy(x,y+2); cout << ((char) 30) << ((char) 190) << " " << ((char) 190) << ((char) 30);
    gotoxy(23,2);  cout << "X: " << (x-2) << " | Y: " << (y-3) << "  ";
}

void ship::borrar(){
    gotoxy(x,y);    cout << "     ";
    gotoxy(x,y+1);  cout << "     ";
    gotoxy(x,y+2);  cout << "     ";
}

void ship::mover(char tecla){
    // if(kbhit()){
    //     char tecla = getch();
    borrar();
        
    if(tecla == IZQUIERDA) x--;
    if(tecla == DERECHA) x++;
    if(tecla == ARRIBA) y--;
    if(tecla == ABAJO) y++;

    if(x<3)x=3;
    if(x>72)x=72;
    if(y<4)y=4;
    if(y>22)y=22;
    if(tecla == 'e') animacion_morir();
    pintar();
    // }
}

void ship::pintar_corazones(){
    gotoxy(50,2); cout << "Vidas " << vidas;
    gotoxy(64,2); cout << "Salud";
    gotoxy(70,2); cout << "     ";

    for(int i = 1; i <= corazones; i++){
        gotoxy(70+i,2); cout << ((int) 3);
    }
}

void ship::perder_salud(){
    corazones--;
    if(corazones <= 0){
        corazones = 3;
        vidas--;
        animacion_morir();
        if(vidas <= 0){

        }
    }
    pintar();
}

void ship::animacion_morir(){
    borrar();
    gotoxy(x,y);    cout << "  *  ";
    gotoxy(x,y+1);  cout << " *** ";
    gotoxy(x,y+2);  cout << "  *  ";
    Sleep(100);

    borrar();
    gotoxy(x,y);    cout << " *** ";
    gotoxy(x,y+1);  cout << "** **";
    gotoxy(x,y+2);  cout << " *** ";
    Sleep(100);

    borrar();
    gotoxy(x,y);    cout << "** **";
    gotoxy(x,y+1);  cout << "*   *";
    gotoxy(x,y+2);  cout << "** **";
    Sleep(100);

    borrar();
    gotoxy(x,y);    cout << "*   *";
    gotoxy(x,y+1);  cout << "     ";
    gotoxy(x,y+2);  cout << "*   *";
    Sleep(100);
    borrar();
}