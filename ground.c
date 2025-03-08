#include "ground.h"

void groundCreate(objBox *ground) {
    ground->width = 100;
    ground->height = 1;
    ground->str = groundFrame;
}

void groundDraw(objBox *ground, int y) {
    objBoxDraw(ground,y,0);
    objBoxShift(ground);
}