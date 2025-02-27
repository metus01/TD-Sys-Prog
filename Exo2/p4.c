// ldd: -lncurses
#include "ncurses.h"
#include <time.h>
#include <stdlib.h>

void INIT_SCREEN(void)
{
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
}

void DONE_SCREEN(void)
{
    endwin();
    exit(0);
}

#define PLAYERS 2
char CHIP[PLAYERS] = "XO";

#define SIZE 16

char board[SIZE][SIZE];

int main(void)
{
    INIT_SCREEN();
    //init_board();
    //play();
    //getch();
    //DONE_SCREEN();
}