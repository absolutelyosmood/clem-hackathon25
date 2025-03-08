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
    
    int alive = TRUE, collision = 0, type;
    char input;
    while(alive) {
        // Get input from user
        input = getch();
        if (input ==' ') {
            playerJump(&player);
        }
        else if (input == '[') {
            enemySpawnCactus();
        }
        else if (input == ']') {
            enemySpawnBird();
        }

        // Draw screen
        playerDraw(&player);
        groundDraw(&ground,PLAYER_Y + player.frame.height);
        collision = enemyDraw(&type);
        if (type == ENEMY_TYPE_CACTUS && (collision == 1 && player.jump == 0)) {
            alive = FALSE;
        }
        else if (type == ENEMY_TYPE_BIRD && (collision ==1 && player.jump == 1)) {
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