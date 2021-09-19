#include <ncurses.h>
#include <string>

std::string VERSION = "21.09.19 DEV BUILD";
std::string list[5] = {"Project one", "Project Two", "Project Three", "Project Four", "Project Five"};
char ch;


int main(){
    // Set window up
    WINDOW *wind = initscr(); // Store window
    start_color();
    use_default_colors();

    init_pair(1, COLOR_RED, -1);
    box(wind,'|','-');
    curs_set(0); // Don't display cursor
    refresh();

    printw("TooDoo version ");
    attron(COLOR_PAIR(1)); // Color version red
    printw(VERSION.c_str());
    attroff(COLOR_PAIR(1));
    
    for(int i = 0; i < sizeof(list)/sizeof(list[0]); i++){
        mvprintw(i+2,4,list[i].c_str());
    }
    refresh();
    
    noecho(); // Don't type what the user types
    while((ch = getch()) != 'q'){ // Keep looping until user presses q to quit
        
    }


    endwin();
    return 0;
}