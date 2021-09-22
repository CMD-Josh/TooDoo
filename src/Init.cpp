#include <ncurses.h>
#include <string>

using namespace std;

string VERSION = "21.09.21 DEV BUILD";
string list[5] = {"Project one", "Project Two", "Project Three", "Project Four", "Project Five"};
char* project;
short ch, selectedOption, maxTitle = 0;
const short amountOfProj = sizeof(list)/sizeof(list[0]);


// Function takes an array and the size of the array then outputs the highest number of the largest amount of characters in that array.
int longestWordInArray(string strArr[], size_t str_len){
    short maxEntry = 0;

    for(int i = 0; i < str_len; i++){
        if(strArr[i].length() > maxEntry){
            maxEntry = strArr[i].length();
        }
    }
    return maxEntry;
}

int main(){

    // Load projects into list from a file


    maxTitle = longestWordInArray(list, sizeof(list)/sizeof(list[0]));
    project = new char[maxTitle];

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
    
    for(int i = 0; i < amountOfProj; i++){ // Loop through and print all projects
        if(i == 0){ // Highlight first option
            attron(A_STANDOUT);
        }else{
            attroff(A_STANDOUT);
        }

        string formatString = "";
        formatString.append(" %-");
        formatString.append(std::to_string(maxTitle + 1)); // add 1 character to add a small padding to the right of a project entry
        formatString.append("s");

        sprintf(project, formatString.c_str(), list[i].c_str());
        list[i] = string(project);
        mvprintw(i+2,4,list[i].c_str());
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