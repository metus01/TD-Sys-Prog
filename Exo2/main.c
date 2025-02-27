#include <headers.h>
int main(void)
{
    INIT_SCREEN();
    init_board();
    play();
    getch();
    DONE_SCREEN();
}