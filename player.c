#include "player.h"

#define PLAYER_MAX_TICK 60
#define PLAYER_BASE_X 0
#define PLAYER_BASE_Y 10
#define PLAYER_BASE_JUMP 10

void playerCreate(ObjPlayer *player) {
    player->jump = 0;
    player->tickCur = 0;
    player->frame.width = PLAYER_FRAME_WIDTH;
    player->frame.height = PLAYER_FRAME_HEIGHT;
    player->frame.str = playerFrame;
    return;
}

void playerJump(ObjPlayer *player) {
    player->jump = 1;
    return;
}

void playerDraw(ObjPlayer *player) {
    if (player->jump == 1 && player->tickCur < PLAYER_MAX_TICK) {
        objBoxClear(&player->frame,PLAYER_BASE_Y,PLAYER_BASE_X);
        objBoxDraw(&player->frame,PLAYER_BASE_Y - PLAYER_BASE_JUMP,PLAYER_BASE_X);
        player->tickCur++;
    }
    else {
        player->jump = 0;
        player->tickCur = 0;
        objBoxClear(&player->frame,PLAYER_BASE_Y - PLAYER_BASE_JUMP,PLAYER_BASE_X);
        objBoxDraw(&player->frame,PLAYER_BASE_Y,PLAYER_BASE_X);
    }
}