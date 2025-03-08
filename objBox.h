#ifndef _OBJBOX_H
#define _OBJBOX_H

#include <curses.h>

typedef struct _objBox {
    int width, height;
    char *str;
} objBox;
  
void objBoxDraw(objBox *box, int startY, int startX);
void objBoxClear(objBox *box, int startY, int startX);
void objBoxFill(int startY, int startX, int width, int height, char character);
void objBoxShift(objBox *box);
void objBoxPad(objBox *box, char character);

#endif