#ifndef _PLAYER_H
#define _PLAYER_H

#include "objBox.h"

#define PLAYER_TICK_DELAY 10
#define PLAYER_TICK_AIR 60

#define PLAYER_X 0
#define PLAYER_Y 10
#define PLAYER_BASE_JUMP 10

typedef struct _ObjPlayer {
    int jump, tickCur;
    objBox frame;
} ObjPlayer;

#define PLAYER_FRAME_WIDTH 10
#define PLAYER_FRAME_HEIGHT 6
static char playerFrame[] = {
    ' ', ' ', ' ',  ' ', ' ', ' ', ' ',  '~', '~', '~',
   '\\', ' ', '_',  '_', '_', '_', '_',  '~', 'o', '>',
    ' ', '|', ' ',  ' ', '=', '=', ' ',  ' ', '/', ' ',
    ' ', ' ', '\\', '_', '_', '_', '_',  '/', ' ', ' ',
    ' ', '_', '_',  '/', ' ', ' ', '\\', ' ', ' ', ' ',
    ' ', ' ', ' ',  ' ', ' ', ' ', ' ',  '_', ' ', ' ',
};

void playerCreate(ObjPlayer *player);
void playerJump(ObjPlayer *player);
void playerDraw(ObjPlayer *player);

#endif