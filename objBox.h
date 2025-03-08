#include <curses.h>

typedef struct _objBox {
    int width, height;
    char *str;
} objBox;
  
void objBoxDraw(objBox *box, int startY, int startX);
void objBoxClear(objBox *box, int startY, int startX);