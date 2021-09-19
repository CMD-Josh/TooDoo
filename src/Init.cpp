#include <ncurses.h>
#include <string>

std::string VERSION = "21.09.19";

int main(){
    initscr();
    printw(("TooDoo version " + VERSION).c_str());
    refresh();
    getch();
    endwin();

    return 0;
}