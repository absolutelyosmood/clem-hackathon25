#include "objBox.h"

void objBoxFill(int startY, int startX, int width, int height, char character) {
    for (int y = startY; y < startY + height; y++) {
        for (int x = startX; x < startX + width; x++) {
            mvaddch(y, x, character);
        }
    }
}

void objBoxDraw(objBox *box, int startY, int startX) {
    for (int y = startY; y < startY + box->height; y++) {
        for (int x = startX; x < startX + box->width; x++) {
            mvaddch(y, x, box->str[(y - startY) * box->width + (x - startX)]);
        }
    }
    return;
}


void objBoxShift(objBox *box) {
    char temp;
    int index;
    for (int y = 0; y < box->height; y++) {
        for (int x = 1; x < box->width; x++) {
            index = (y * box->width) + x;
            
            temp = box->str[index];
            box->str[index] = box->str[index - 1];
            box->str[index - 1] = temp;
        }
    }
    return;
}
  
void objBoxClear(objBox *box, int startY, int startX) {
    objBoxFill(startY,startX,box->width,box->height,' ');
    return;
}