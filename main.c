#include <stdio.h>
#include <unistd.h>

#include "objBox.h"

#define FPS 60

void setup_curses();
void unset_curses();
void update();


int main() {
    setup_curses();
    
    int alive = TRUE;
    while(alive) {
        update();
    }

    unset_curses();
}

void update(){
    refresh();
    napms(1000 / FPS);
}






  
void setup_curses() {
    // use return values.  see man pages.  likely just useful for error
    // checking (NULL or non-NULL, at least for init_scr)
    initscr();
    cbreak();
    noecho();
    // needed for cursor keys (even though says keypad)
    keypad(stdscr, true);
    nodelay(stdscr, TRUE);
}
  
  
void unset_curses() {
    keypad(stdscr, false);
    nodelay(stdscr, false);
    nocbreak();
    echo();
    endwin();
}