#include "objBox.h"
#include "player.h"

#define ENEMY_BASE_Y 0
#define ENEMY_START_X 100
#define ENEMY_MAX_SPAWN 5
#define ENEMY_DESPAWN_X 10

static char cactusFrame[] = {
    ' ', ' ',  ' ', '/', '\\', ' ', ' ', ' ',
    ' ', ' ',  ' ', '|',  '|', ' ', '/', '\\',
    '/', '\\', ' ', '|',  '|', ' ', '|', '|',
    '[', '=',  '=', ' ',  '|', ' ', '|', '|',
    ' ', ' ',  ' ', '|',  ' ', '=', '=', ']',
    ' ', ' ',  ' ', '|',  '|', ' ', ' ', ' ',
};

typedef struct _ObjEnemy {
    int tickCur, xPos, speed, spawned;
    objBox frame;
}ObjEnemy;

typedef ObjEnemy objBird;
typedef ObjEnemy objCactus;

void enemyBufferInit();
void enemyDraw();
void enemySpawn();

//Method to spawn a cactus moving with the ground
void cactusCreate();
//Method to spawn a bird moving with the ground
void birdCreate();

