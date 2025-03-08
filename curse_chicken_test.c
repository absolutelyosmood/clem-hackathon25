#include <stdio.h>
#include <unistd.h>

#include "objBox.h"

/*
have an array of potential values
access each one through a %
*/


void setup_curses();
void unset_curses();
void update();

#define PLAYER_MAX_TICK 5
#define PLAYER_BASE_X 0
#define PLAYER_BASE_Y 10
#define PLAYER_BASE_JUMP 10


static char playerStrAsset[] = {
    ' ', ' ', ' ', ' ', '~', '~', '~',
    ' ', ' ', ' ', ' ', '~', 'D', '>',
    ' ', ' ', ' ', '=', '=', '|', ' ',
    '=', '=', '=', '=', '=', '|', ' ',
    ' ', '=', '=', '=', '=', ' ', ' ',
    ' ', ' ', ' ', '/', '\\', ' ', ' ',
};

typedef struct _ObjPlayer {
    int jump, tickCur;
    int x, y;
    objBox box;
} ObjPlayer;

void playerCreate(ObjPlayer *player) {
    player->jump = 0;
    player->tickCur = 0;
    player->box.width = 7;
    player->box.height = 6;
    player->box.str = playerStrAsset;
}

void playerDraw(ObjPlayer *player) {
    if (player->jump == 1 && player->tickCur < PLAYER_MAX_TICK) {
        objBoxClear(&player->box,PLAYER_BASE_Y,PLAYER_BASE_X);
        objBoxDraw(&player->box,PLAYER_BASE_Y - PLAYER_BASE_JUMP,PLAYER_BASE_X);
        player->tickCur++;
    }
    else {
        player->jump = 0;
        player->tickCur = 0;
        objBoxClear(&player->box,PLAYER_BASE_Y - PLAYER_BASE_JUMP,PLAYER_BASE_X);
        objBoxDraw(&player->box,PLAYER_BASE_Y,PLAYER_BASE_X);
    }
}


int main() {
    int x = 0;
    setup_curses();

    ObjPlayer player;
    playerCreate(&player);
    while(TRUE) {
        if (x == 5 && player.jump == 0) {
            player.jump = 1;
        }

        x = (x + 1) % 15;
        playerDraw(&player);
        update();
    }

    unset_curses();
}

void update(){
    refresh();
    sleep(1); 
}






  
void setup_curses() {
    // use return values.  see man pages.  likely just useful for error
    // checking (NULL or non-NULL, at least for init_scr)
    initscr();
    cbreak();
    noecho();
    // needed for cursor keys (even though says keypad)
    keypad(stdscr, true);
}
  
  
void unset_curses() {
    keypad(stdscr, false);
    nodelay(stdscr, false);
    nocbreak();
    echo();
    endwin();
}
  