#include "objBox.h";

#define PLAYER_TICK_DELAY 10
#define PLAYER_TICK_AIR 60

#define PLAYER_X 0
#define PLAYER_Y 10
#define PLAYER_BASE_JUMP 10

typedef struct _ObjPlayer {
    int jump, tickCur;
    objBox frame;
} ObjPlayer;

static char playerFrame[] = {
    ' ', ' ', ' ', ' ', '~', '~', '~',
    ' ', ' ', ' ', ' ', '~', 'D', '>',
    ' ', ' ', ' ', '=', '=', '|', ' ',
    '=', '=', '=', '=', '=', '|', ' ',
    ' ', '=', '=', '=', '=', ' ', ' ',
    ' ', ' ', ' ', '/', '\\', ' ', ' ',
};

void playerCreate(ObjPlayer *player, int x, int y);
void playerJump(ObjPlayer *player);
void playerDraw(ObjPlayer *player);