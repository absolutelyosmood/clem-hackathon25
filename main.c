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
int highscore = 0;
char score_text[30] = {
  ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
};
char highscore_text[30] = {
  ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
};


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
    score = 0;

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
        else if (input == 'q' || input == 'r') {
            alive = FALSE;
        }

        // Draw screen
        playerDraw(&player);
        groundDraw(&ground,PLAYER_Y + player.frame.height);
        collision = enemyDraw(&type);
        if (type == ENEMY_TYPE_CACTUS && (collision == 1 && player.jump == 0)) {
            alive = FALSE;
            if (score > highscore){
              highscore = score;
            }
        }
        else if (type == ENEMY_TYPE_BIRD && (collision ==1 && player.jump == 1)) {
            alive = FALSE;
            if (score > highscore){
              highscore = score;
            }
        }

        update();
    }

}

void update(){
    refresh();
    napms(1000 / FPS);
    score++;
    sprintf(score_text, "Score: %d",score);
    sprintf(highscore_text, "Highscore: %d",highscore);
    mvprintw(0, 90, highscore_text);
    mvprintw(1, 90, score_text);
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
