#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "player.h"
#include "ground.h"
#include "enemy.h"
#include "menu.h"

#define FPS 60

void setup_curses();
void unset_curses();
void update();

void GameRuntime();
int score = 0;
char *score_text;


int main() {
    setup_curses();

    while (TRUE) {
        objMenuDraw();
        GameRuntime();
        clear();
    }

    unset_curses();
}

void GameRuntime() {
    // Declarations
    objBox ground;
    ObjPlayer player;
    int alive = TRUE, collision = 0, type;
    char input;

    // Initialize environment
    enemyBufferInit();
    groundCreate(&ground);
    playerCreate(&player);
    score_text = (char*)malloc(sizeof(char)*30);

    // Runtime
    while(alive) {
        // Get input from user
        input = getch();
        if (input ==' ') {
            playerJump(&player);
        }
        else if (input == '[') {
            enemySpawn(ENEMY_TYPE_CACTUS);
        }
        else if (input == ']') {
            enemySpawn(ENEMY_TYPE_BIRD);
        }
        else if (input == 'x') {
            player.jump = 0;
        }
        else if (input == 'q') {
          break;
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

}

void update(){
    refresh();
    napms(1000 / FPS);
    score++;
    sprintf(score_text, "Score: %d", score);
    mvaddstr(0,100, score_text);
}

// Sets up the curses terminal, displaying game output
void setup_curses() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);
    nodelay(stdscr, TRUE);
    free(score_text);
}
  
// Takes down the curses terminal
void unset_curses() {
    keypad(stdscr, false);
    nodelay(stdscr, false);
    nocbreak();
    echo();
    endwin();
}
