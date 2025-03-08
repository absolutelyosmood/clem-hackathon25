#include "objBox.h"
#include "player.h"

#define ENEMY_BASE_Y 9
#define ENEMY_START_X 100
#define ENEMY_START_Y 10
#define ENEMY_MAX_SPAWN 5
#define ENEMY_COLLISION_X 10

#define ENEMY_TYPE_NULL -1
#define ENEMY_TYPE_CACTUS 0
#define ENEMY_TYPE_BIRD 1

#define ENEMY_CACTUS_WIDTH 8
#define ENEMY_CACTUS_HEIGHT 6
static char cactusFrame[] = {
    ' ', ' ',  ' ', '/', '\\', ' ', ' ', ' ',
    ' ', ' ',  ' ', '|',  '|', ' ', '/', '\\',
    '/', '\\', ' ', '|',  '|', ' ', '|', '|',
    '[', '=',  '=', ' ',  '|', ' ', '|', '|',
    ' ', ' ',  ' ', '|',  ' ', '=', '=', ']',
    ' ', ' ',  ' ', '|',  '|', ' ', ' ', ' ',
};

#define ENEMY_BIRD_WIDTH 13
#define ENEMY_BIRD_HEIGHT 5
static char birdFrame[] = {
    ' ', '_',  ' ',  ' ', ' ', ' ', ' ', ' ', ' ',  ' ', ' ', '_', '_',
    '<', '+',  '\\', '_', '_', '_', '_', '_', '_',  '_', '/', ' ', '/',
    ' ', '\\', ' ',  ' ', '-', '-', '-', ' ', ' ',  ' ', '_', '/', ' ',
    ' ', ' ',  '\\', '_', '_', '_', '_', '_', '_',  '|', ' ', ' ', ' ',
    ' ', ' ',  ' ',  ' ', ' ', ' ', ' ', ' ', '\\', ' ', ' ', ' ', ' ',
};

typedef struct _ObjEnemy {
    int spawned, type;
    int xPos, yPos;
    int speed;
    objBox frame;
}ObjEnemy;

typedef ObjEnemy objBird;
typedef ObjEnemy objCactus;

void enemyBufferInit();
int enemyDraw(int *type);

void enemySpawnCactus();
void enemySpawnBird();

//Method to spawn a cactus moving with the ground
void cactusCreate();
//Method to spawn a bird moving with the ground
void birdCreate();

