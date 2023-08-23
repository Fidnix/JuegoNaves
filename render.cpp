#include "render.hpp"

using namespace std;

void gotoxy(int x, int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;

    SetConsoleCursorPosition(hCon, dwPos);
}

void cursor_hide(){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cci;

    cci.dwSize = 100;
    cci.bVisible = FALSE;

    SetConsoleCursorInfo(hCon, &cci);
}

void limpiar_pantalla(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    
    int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1,
        rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    for(int i = 0; i < columns; i++){
        for(int j = 0; j < rows; j++){
            gotoxy(i,j); cout << " ";
        }
    }
}

void pintar_limites(){
    for (int i = 3; i < 77; i++){
        gotoxy(i,3); cout << ( (char) 205 );
        gotoxy(i,25); cout << ( (char) 205 );
    }
    for (int i = 4; i < 25; i++){
        gotoxy(2,i); cout << ( (char) 186 );
        gotoxy(77,i); cout << ( (char) 186 );
    }
    
    gotoxy(2,3); cout << ( (char) 201 );
    gotoxy(77,3); cout << ( (char) 187 );
    gotoxy(2,25); cout << ( (char) 200 );
    gotoxy(77,25); cout << ( (char) 188 );
}

void pantalla_final(){
    for(int i = 0; i <=77;i++)
        for(int i2 = 0; i2 <=26;i2++){
            gotoxy(i, i2); cout << " ";
        }

    gotoxy(5, 5); cout << " __   __   __   __      __        _____   __";
    gotoxy(5, 6); cout << "|    |  | |    |       |  | |  |    |    |  |";
    gotoxy(5, 7); cout << "|__  |__| |__  |__     |__| |  |    |    |  |";
    gotoxy(5, 8); cout << "|    | |  |       |    |    |  |    |    |  |";
    gotoxy(5, 9); cout << "|__  |  | |__   __|    |    |__|    |    |__|";
    Sleep(3500);
    getch(); // Detiene la pantalla hasta que se presione una tecla
}