#include <ncurses.h>
#include <unistd.h>  /* only for sleep() */

int SomethingIsPressed(void)
{
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}

int main(void)
{
    initscr();

    cbreak();
    noecho();
    nodelay(stdscr, TRUE);

    scrollok(stdscr, TRUE);
    printw("Press Something...\n");
    while (1) {
        if (SomethingIsPressed()) {
            printw("Something is detected! his index is: %d\n", getch());
            refresh();
        }
    }
}
