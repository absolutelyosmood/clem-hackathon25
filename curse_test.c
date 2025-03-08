#include <stdio.h>
#include <curses.h>
#include <unistd.h>

#include "objBox.h"

void setup_curses();
void unset_curses();
void update();


int glob_x = 0;
int switch_pos = 10;
int glob_y = 0;

int main(int argc, char *argv[])
{
  setup_curses();
  while(TRUE)
  {
    update();
  }
  unset_curses();
}

/*
update is Jumping if it is not already set
if it is set increment the tick
*/

void update(){
  mvaddch(glob_y, glob_x++, 'a');
  mvaddch(glob_y, glob_x-1, ' ');
  //mvaddstr(glob_y++, glob_x++, "Hello World");
  refresh();
  sleep(1); 
}

//void print_array(stdscr, array)
//{
  //  height, width = stdscr.getmaxyx()
    //y = height // 2 - len(array) // 2
    //x = width // 2 - max(len(s) for s in array) // 2
//    for i, text in enumerate(array):
  //      stdscr.addstr(y + i, x, text)
    //stdscr.refresh()
//}

void setup_curses()
{
  // use return values.  see man pages.  likely just useful for error
  // checking (NULL or non-NULL, at least for init_scr)
  initscr();
  cbreak();
  noecho();
  // needed for cursor keys (even though says keypad)
  keypad(stdscr, true);
}


void unset_curses()
{
  keypad(stdscr, false);
  nodelay(stdscr, false);
  nocbreak();
  echo();
  endwin();
}
