#include <ncurses.h>
#include <stdio.h>
#define SIZE 16

int main() {
    int y, x;

    // Initialiser ncurses
    initscr();
    noecho();
    cbreak();
    char board[SIZE][SIZE];

    // Obtenir la position actuelle du curseur
    //getyx(stdscr, y, x);

    // coordonne du curseur

    for (int i = 0; i < SIZE+1; i++)
    {
        if(i>=1)
        {
            //getyx(stdscr, y, x);
            //printw(".");
            
        }
        
        for (int j = 0; j < SIZE+1; j++)
        {
            if(j>=1)
        {
            //getyx(stdscr, y, x);
            //printw(".");
            move(i,(j*2)-1);
            printw("X");
           
        }
            move(i, j * 2);
            printw("|");
        }
    }
    move(SIZE, 0);
    for (int j = 0; j < SIZE ; j++)
    {
        printw("+-");
    }
    move(SIZE, SIZE * 2);
    printw("+");
 
    move(SIZE + 1, 1);
    const char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < SIZE ; i++) {
        printw("%c ", alphabet[i]);    }
    move(SIZE+2 , 0);
    printw("player 1 ?");

    
   /* for (int i = 0; i < 10 ; i++)
    {
        getyx(stdscr, y, x);
        printw("Curseur à la position : (%d, %d)\n", y, x);
    }*/
    refresh();

    // Attendre une touche pour quitter
    
    getch();

    // coordonne du curseur
    // Terminer ncurses
    endwin();

    return 0;

}
