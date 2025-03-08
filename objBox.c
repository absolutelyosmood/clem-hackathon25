#include "objBox.h"

// Fill an area of box area of space with a certain character
void objBoxFill(int startY, int startX, int width, int height, char character) {
    for (int y = startY; y < startY + height; y++) {
        for (int x = startX; x < startX + width; x++) {
            mvaddch(y, x, character);
        }
    }
}

// Draws a given box at a top left coordinate (x,y).
void objBoxDraw(objBox *box, int startY, int startX) {
    for (int y = startY; y < startY + box->height; y++) {
        for (int x = startX; x < startX + box->width; x++) {
            mvaddch(y, x, box->str[(y - startY) * box->width + (x - startX)]);
        }
    }
    return;
}

// NEED TO TEST THIS
// copies a src box into a dst box (SRC MUST HAVE SAME OR SMALLER WIDTH HEIGHT)
void objBoxCopy(objBox *src, objBox *dst, int startX, int startY) {
    char character;
    for (int y = 0; y < src->height; y++) {
        for (int x = 0; x < src->width; x++) {
            character = src->str[y * src->width + x];
            mvaddch(y + startY, x + startX, dst->str[character]);
        }
    }
}

// Shifts a given box to the left by one (wraps around)
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

// Clears an area of the screen
void objBoxClear(objBox *box, int startY, int startX) {
    objBoxFill(startY,startX,box->width,box->height,' ');
    return;
}

void objBoxPad(objBox *box, char character) {
    objBoxFill(0,0,box->width,box->height,character);
}