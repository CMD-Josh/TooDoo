#include <ncurses.h>
#include <string>

std::string VERSION = "21.09.19 DEV BUILD";
std::string list[5] = {"Project one", "Project Two", "Project Three", "Project Four", "Project Five"};
short ch, selectedOption = 0;
const short amountOfProj = sizeof(list)/sizeof(list[0]);


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
    
    for(int selectedOption = 0; selectedOption < amountOfProj; selectedOption++){ // Loop through and print all projects
        if(selectedOption == 0){ // Highlight first option
            attron(A_STANDOUT);
        }else{
            attroff(A_STANDOUT);
        }

        mvprintw(selectedOption+2,4,list[selectedOption].c_str());
    }
    refresh();

    keypad(wind,true);
    
    noecho(); // Don't type what the user types
    while((ch = getch()) != 'q'){ // Keep looping until user presses q to quit

        mvprintw(selectedOption+2, 4, list[selectedOption].c_str());

        switch (ch){
        case KEY_UP:
            selectedOption--;
            selectedOption = (selectedOption<0) ? amountOfProj-1 : selectedOption;
            break;
        case KEY_DOWN:
            selectedOption++;
            selectedOption = (selectedOption>amountOfProj-1) ? 0 : selectedOption;
            break;
        }

        attron(A_STANDOUT);
        mvprintw(selectedOption+2,4,list[selectedOption].c_str());
        attroff(A_STANDOUT);
    }

    delwin(wind);
    endwin();
    return 0;
}