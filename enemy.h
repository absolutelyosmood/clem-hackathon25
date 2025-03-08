#include "objBox.h"
#include "player.h"

typedef struct _ObjEnemy {
    int tickCur, xPos, speed;
    objBox frame;
}ObjEnemy;

typedef ObjEnemy objBird;
typedef ObjEnemy objCactus;

//Method to spawn a cactus moving with the ground
void cactusCreate();
//Method to spawn a bird moving with the ground
void birdCreate();

