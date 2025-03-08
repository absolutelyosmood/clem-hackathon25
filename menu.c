#include "menu.h"

void objMenuDraw() {
    objBox menuBox = {.width=MENU_FRAME_WIDTH,.height=MENU_FRAME_HEIGHT,.str=menuText};
    objBoxDraw(&menuBox,0,0);
  
    while (getch() == -1) {
        continue;
    }

    objBoxClear(&menuBox,0,0);
  }
  