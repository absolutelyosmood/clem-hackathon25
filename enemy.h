#include "objBox.h"
#include "player.h"

#define ENEMY_BASE_Y 9
#define ENEMY_START_X 100
#define ENEMY_MAX_SPAWN 5
#define ENEMY_COLLISION_X 10

static char cactusFrame[] = {
    ' ', ' ',  ' ', '/', '\\', ' ', ' ', ' ',
    ' ', ' ',  ' ', '|',  '|', ' ', '/', '\\',
    '/', '\\', ' ', '|',  '|', ' ', '|', '|',
    '[', '=',  '=', ' ',  '|', ' ', '|', '|',
    ' ', ' ',  ' ', '|',  ' ', '=', '=', ']',
    ' ', ' ',  ' ', '|',  '|', ' ', ' ', ' ',
};

static char birdFrame[] = {
    ' ', '_',  ' ',  ' ', ' ', ' ', ' ', ' ', ' ',  ' ', ' ', '_', '_',
    '<', '+',  '\\', '_', '_', '_', '_', '_', '_',  '_', '/', ' ', '/',
    ' ', '\\', ' ',  ' ', '-', '-', '-', ' ', ' ',  ' ', '_', '/', ' ',
    ' ', ' ',  '\\', '_', '_', '_', '_', '_', '_',  '|', ' ', ' ', ' ',
    ' ', ' ',  ' ',  ' ', ' ', ' ', ' ', ' ', '\\', ' ', ' ', ' ', ' ',
};

typedef struct _ObjEnemy {
    int tickCur, xPos, speed, spawned;
    objBox frame;
}ObjEnemy;

typedef ObjEnemy objBird;
typedef ObjEnemy objCactus;

void enemyBufferInit();
int enemyDraw();
void enemySpawn();


