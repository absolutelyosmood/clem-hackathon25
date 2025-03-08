/*
keep an array of a maximum amount of enemys
keep a tick cooldown to stop from spawning too many enemys

*/

#include "enemy.h"

ObjEnemy EnemyBuffer[ENEMY_MAX_SPAWN];

int enemyFindEmptySlot() {
    for (int i = 0; i < ENEMY_MAX_SPAWN; i++) {
        if (EnemyBuffer[i].spawned == 0) {
            return i;
        }
    }
}

void enemyBufferInit() {
    for (int i = 0; i < ENEMY_MAX_SPAWN; i++) {
        EnemyBuffer[i].spawned = 0;
    }
}

// void enemySpawn() {
//     int slot = enemyFindEmptySlot();

// }