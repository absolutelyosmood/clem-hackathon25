#include <stdio.h>
#include <unistd.h>

#include "player.h"
#include "ground.h"
#include "enemy.h"

#define FPS 60

void setup_curses();
void unset_curses();
void update();

objBox ground;
ObjPlayer player;

int main() {
    setup_curses();

    enemyBufferInit();
    groundCreate(&ground);
    playerCreate(&player);

    enemySpawn();
    
    int alive = TRUE, collision = 0;
    char input;
    while(alive) {
        input = getch();
        if (input ==' ') {
            playerJump(&player);
        }

        playerDraw(&player);
        groundDraw(&ground,PLAYER_Y + player.frame.height);
        collision = enemyDraw();
        if (collision == 1 && player.jump == 0) {
            alive = FALSE;
        }

        update();
    }

    unset_curses();
}

void update(){
    refresh();
    napms(1000 / FPS);
}

// Sets up the curses terminal, displaying game output
void setup_curses() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);
    nodelay(stdscr, TRUE);
}
  
// Takes down the curses terminal
void unset_curses() {
    keypad(stdscr, false);
    nodelay(stdscr, false);
    nocbreak();
    echo();
    endwin();
}