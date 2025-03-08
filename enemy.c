/*
keep an array of a maximum amount of enemys
keep a tick cooldown to stop from spawning too many enemys

*/

#include "enemy.h"

static ObjEnemy EnemyBuffer[ENEMY_MAX_SPAWN];

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

/*
iterate through each enemy in the buffer
if enemy exist get its shift amount

return value indicating if it passes a given x value
*/
int enemyDraw() {
    int collisionDetected = 0;

    for (int i = 0; i < ENEMY_MAX_SPAWN; i++) {
        if (EnemyBuffer[i].spawned == 1) {
            objBoxClear(&EnemyBuffer[i].frame,ENEMY_BASE_Y,EnemyBuffer[i].xPos);

            EnemyBuffer[i].xPos = EnemyBuffer[i].xPos - EnemyBuffer[i].speed;
            objBoxDraw(&EnemyBuffer[i].frame,ENEMY_BASE_Y,EnemyBuffer[i].xPos);

            if (EnemyBuffer[i].xPos < ENEMY_COLLISION_X) {
                collisionDetected = 1;
            }
        }
    }

    return collisionDetected;
}

void enemySpawn() {
    int i = enemyFindEmptySlot();
    if (i != -1) {
        EnemyBuffer[i].spawned = 1;
        EnemyBuffer[i].speed = 1;
        EnemyBuffer[i].tickCur = 0;
        EnemyBuffer[i].xPos = 100;
    }
}