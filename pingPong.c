// Este programa simula o movimento de uma bola de ping-pong

// Bibliotecas
#include <stdio.h>
#include <conio.h>
#include <windows.h>

// Protótipos
void gotoxy (int x, int y);
void getConsoleSize (int * width, int * height);

// Definições das funções
void gotoxy (int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), coord);
}

void getConsoleSize (int * width, int * height) {
    CONSOLE_SCREEN_BUFFER_INFO consoleBufferInfo;
    HANDLE handleConsole = GetStdHandle (STD_OUTPUT_HANDLE);

    if (GetConsoleScreenBufferInfo (handleConsole, &consoleBufferInfo)) {
        * width = consoleBufferInfo.srWindow.Right - consoleBufferInfo.srWindow.Left + 1;
        * height = consoleBufferInfo.srWindow.Bottom - consoleBufferInfo.srWindow.Top + 1;
    } else {
        * width = 0;
        * height = 0;
    }
}

// Corpo do programa
int main(void) {
    
    int x = 1, y = 1, dx = 1, dy = 1, width, height;

    while ( ! kbhit() ) {
        getConsoleSize (&width, &height);
        gotoxy (x, y);
        putchar (254);
        Sleep (250);
        gotoxy (x, y);
        putchar (' ');
        x += dx;
        y += dy;
        if ( x==1 || x==width) dx = -dx;
        if ( y==1 || y==height) dy = -dy;
    }

    return (0);
}