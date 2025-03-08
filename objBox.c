#include "objBox.h"

void objBoxDraw(objBox *box, int startY, int startX) {
    for (int y = startY; y < startY + box->height; y++) {
        for (int x = startX; x < startX + box->width; x++) {
            mvaddch(y, x, box->str[x + y]);
        }
    }
    return;
}
  
void objBoxClear(objBox *box, int startY, int startX) {
    for (int y = startY; y < startY + box->height; y++) {
        for (int x = startX; x < startX + box->width; x++) {
            mvaddch(y, x, ' ');
        }
    }
    return;
}