#include <stdio.h>
#include <unistd.h>

#include "player.h"
#include "ground.h"

#define FPS 60

void setup_curses();
void unset_curses();
void update();


int main() {
    setup_curses();

    objBox ground;
    groundCreate(&ground);

    ObjPlayer player;
    playerCreate(&player);
    
    int alive = TRUE;
    char input;
    while(alive) {
        input = getch();
        if (input ==' ') {
            playerJump(&player);
        }

        playerDraw(&player);
        //groundDraw(&ground,PLAYER_Y + player.frame.height - 1);

        update();
    }

    unset_curses();
}

void update(){
    refresh();
    napms(1000 / FPS);
}
  
void setup_curses() {
    initscr();
    cbreak();
    noecho();
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