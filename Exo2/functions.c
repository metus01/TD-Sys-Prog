#include <ncurses.h>
#define SIZE 16
#define PLAYERS 2

void init_board(void)
{
    // la fonction initialise la grille de jeu en la vidant entièrement.
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            move(i, j * 2);
            printw("|");
        }
    }
    move(SIZE, 0);
    for (int j = 0; j < SIZE - 1; j++)
    {
        printw("+-");
    }
    move(SIZE, (SIZE - 1) * 2);
    printw("+");
}
void draw_board(void)
{
    refresh();
}
int get_col(void)
{
    char input =   getch(); 
    if(input == KEY_BACKSPACE)
    {
        return -1;
    }
    char CHIP[PLAYERS] = "XO";
    for (int i = 0; i < PLAYERS; i++)
    {
        /* code */
        if(input == CHIP[i])
        {
            break;
            // renoyer le numéro de colonne correspondant
        }
    }
    
}
