#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <list>

using namespace std;

#include "render.hpp"
#include "ship.hpp"
#include "asteroide.hpp"
#include "bala.hpp"

int main(){
    // Pantalla inicial del juego
    cursor_hide();
    limpiar_pantalla();
    pintar_limites();

    // Crea al jugador
    ship shipP(36, 22, 3, 3);
    shipP.pintar();
    shipP.pintar_corazones();

    // Crea una lista de listaAsteroides
    list<asteroides*> listaAsteroides;
    list<asteroides*>::iterator iteAsteroide;

    for(int i=0; i<5;i++)
        listaAsteroides.push_back(new asteroides(rand()%71+4, rand()%5+4));

    // Crea la lista de balas
    list<bala*> listaBalas;
    list<bala*>::iterator iteBalas;

    // Valores fundamentales del juego
    bool game_over = false;
    int puntos = 0;

    gotoxy(4,2); cout << "Puntos: " << puntos;

    while(!game_over){
        // Reconocimiento de tecla
        if(kbhit()){
            char tecla_bala = getch();
            if(tecla_bala=='a')
                listaBalas.push_back(new bala(shipP.return_X()+2,shipP.return_Y()-1));
            else
                shipP.mover(tecla_bala);
        }

        for(iteBalas = listaBalas.begin(); iteBalas != listaBalas.end();iteBalas++){
            (*iteBalas)->mover();
            if((*iteBalas)->fuera()){
                gotoxy((*iteBalas)->return_x(),(*iteBalas)->return_y());cout << " ";
                delete(*iteBalas);
                iteBalas = listaBalas.erase(iteBalas);
            }
        }

        for(iteAsteroide = listaAsteroides.begin();iteAsteroide!=listaAsteroides.end();iteAsteroide++){
            (*iteAsteroide)->mover();
            (*iteAsteroide)->choque(shipP);
        }

        for(iteAsteroide = listaAsteroides.begin(); iteAsteroide != listaAsteroides.end();iteAsteroide++){
            for(iteBalas = listaBalas.begin(); iteBalas != listaBalas.end();iteBalas++){
                if((*iteBalas)->return_x()==(*iteAsteroide)->return_x() && ( (*iteBalas)->return_y()==(*iteAsteroide)->return_y()+1 || (*iteBalas)->return_y()==(*iteAsteroide)->return_y())){
                    gotoxy( (*iteBalas)->return_x(), (*iteBalas)->return_y() ); cout << " ";
                    delete(*iteBalas);
                    iteBalas = listaBalas.erase(iteBalas);

                    listaAsteroides.push_back(new asteroides(rand()%71+4, 4));
                    gotoxy( (*iteAsteroide)->return_x(), (*iteAsteroide)->return_y() ); cout << " ";
                    delete(*iteAsteroide);
                    iteAsteroide = listaAsteroides.erase(iteAsteroide);

                    puntos++;
                    gotoxy(12,2); cout << puntos;
                }
            }
        }
        
        if(shipP.return_hearts()==0)
            game_over = true;
        
        Sleep(30); // Llegaria a ser el tiempo por cada fotograma
    }

    pantalla_final();
    return 0;
}