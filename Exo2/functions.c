#include <ncurses.h>
#define SIZE 16
void init_board(void)
{
    // la fonction initialise la grille de jeu en la vidant entièrement.
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            move(i * 2, j * 4);
            printw("+---");
        }
        move(i * 2 + 1, 0);
        for (int j = 0; j < COLS; j++)
        {
            printw("|   "); 
        }
        printw("|\n"); 
    }
}
