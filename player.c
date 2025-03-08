#include "player.h"

void playerCreate(ObjPlayer *player, int x, int y) {
    player->jump = 0;
    player->tickCur = 0;
    player->frame.width = 7;
    player->frame.height = 6;
    player->frame.str = playerFrame;
    return;
}

void playerJump(ObjPlayer *player) {
    player->jump = 1;
    return;
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