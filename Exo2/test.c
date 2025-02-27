#include <ncurses.h>
#define SIZE 5
void INIT_SCREEN(void)
{
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
}
/*void init_board(void)
{
    // la fonction initialise la grille de jeu en la vidant entièrement.
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            move(i,j*2);
            printw("|");
        }
    }
   move(0,0);
   printw("|");
   printf("Rien ne fonctionne");
}
void DONE_SCREEN(void)
{
    endwin();
    //exit(0);
}
int main()
{
    INIT_SCREEN();
    init_board();
    DONE_SCREEN();
}*/
int main()
{
    initscr(); // Initialise ncurses
    // move(0, 0);  // Place le curseur en haut à gauche
    // printw("|"); // Affiche "|"
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            move(i, j * 2);
            printw("|"); // Affichage des séparateurs verticaux
        }
    }
    move(SIZE, 0); // Placer le curseur en dessous de la grille
        for (int j = 0; j < SIZE-1; j++)
        {
            printw("+-"); // Afficher la ligne du bas
        }
        move(SIZE,(SIZE-1)*2);
        printw("+");

    refresh(); // Met à jour l'affichage
    getch();   // Attend une entrée utilisateur
    endwin();  // Ferme ncurses
    return 0;
}