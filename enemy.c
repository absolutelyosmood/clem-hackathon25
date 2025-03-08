/*
keep an array of a maximum amount of enemys
keep a tick cooldown to stop from spawning too many enemys

*/

#include "enemy.h"

static ObjEnemy EnemyBuffer[ENEMY_MAX_SPAWN];
static int EnemySpeed = 1;
static int EnemySpawnTick = 0;

static int enemyFindEmptySlot() {
    for (int i = 0; i < ENEMY_MAX_SPAWN; i++) {
        if (EnemyBuffer[i].spawned == 0) {
            return i;
        }
    }
    return -1;
}

void enemyBufferInit() {
    for (int i = 0; i < ENEMY_MAX_SPAWN; i++) {
        EnemyBuffer[i].spawned = 0;
        EnemyBuffer[i].frame.str = cactusFrame;
        EnemyBuffer[i].frame.width = 8;
        EnemyBuffer[i].frame.height = 6;
    }
}

void enemyIncreaseSpeed(int amount) {
    EnemySpeed += amount;
}

/*
iterate through each enemy in the buffer
if enemy exist get its shift amount

return value indicating if it passes a given x value
*/
int enemyDraw(int *type) {
    int collisionDetected = 0;
    *type = ENEMY_TYPE_NULL;

    for (int i = 0; i < ENEMY_MAX_SPAWN; i++) {
        if (EnemyBuffer[i].spawned == 1) {
            objBoxClear(&EnemyBuffer[i].frame,EnemyBuffer[i].yPos,EnemyBuffer[i].xPos);

            EnemyBuffer[i].xPos = EnemyBuffer[i].xPos - EnemySpeed;
            objBoxDraw(&EnemyBuffer[i].frame,EnemyBuffer[i].yPos,EnemyBuffer[i].xPos);

            if (EnemyBuffer[i].xPos <= 0) {
                EnemyBuffer[i].spawned = 0;
                objBoxClear(&EnemyBuffer[i].frame,EnemyBuffer[i].yPos,EnemyBuffer[i].xPos);
            }
            else if (EnemyBuffer[i].xPos < ENEMY_COLLISION_X) {
                collisionDetected = 1;
                *type = EnemyBuffer[i].type;
            }
        }
    }

    if (EnemySpawnTick) {
        EnemySpawnTick--;
    }
    
    return collisionDetected;
}

// void enemySpawn() {
//     int i = enemyFindEmptySlot();
//     if (i != -1) {
//         EnemyBuffer[i].spawned = 1;
//         EnemyBuffer[i].speed = 1;
//         EnemyBuffer[i].xPos = 100;
//         EnemyBuffer[i].type = ENEMY_TYPE_CACTUS;
//     }
// }

static void SpawnCactus(int index) {
    EnemyBuffer[index].frame.height = ENEMY_CACTUS_HEIGHT;
    EnemyBuffer[index].frame.width = ENEMY_CACTUS_WIDTH;
    EnemyBuffer[index].frame.str = cactusFrame;

    EnemyBuffer[index].xPos = 100;
    EnemyBuffer[index].yPos = 9;
}

static void SpawnBird(int index) {
    EnemyBuffer[index].frame.height = ENEMY_BIRD_HEIGHT;
    EnemyBuffer[index].frame.width = ENEMY_BIRD_WIDTH;
    EnemyBuffer[index].frame.str = birdFrame;

    EnemyBuffer[index].xPos = 100;
    EnemyBuffer[index].yPos = 0;
}

void enemySpawn(int type) {
    int i = enemyFindEmptySlot();
    if (i < 0 || EnemySpawnTick != 0) {
        return;
    }

    EnemySpawnTick = ENEMY_SPAWN_TICK;
    EnemyBuffer[i].spawned = 1;
    EnemyBuffer[i].type = type;
    if (type == ENEMY_TYPE_CACTUS) {
        SpawnCactus(i);
    }
    else {
        SpawnBird(i);
    }
}
