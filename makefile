# The makefile for Codename:Chicken.
# Type:
#   make         -- to build program lab2
#   make design  -- check for simple design errors (incomplete)
#   make driver  -- to compile testing program
#   make clean   -- to delete object files, executable, and core
#

full: enemy.o objBox.o player.o ground.o 
	gcc -g main.c menu.c enemy.o objBox.o player.o ground.o -lcurses -o game 

mwin: enemy.o objBox.o player.o ground.o 
	gcc -g multi_window_test.c enemy.o objBox.o player.o ground.o -lcurses -o game 

enemy.o : enemy.c objBox.o enemy.h objBox.h 
	gcc -g -c enemy.c objBox.c

objBox.o : objBox.c objBox.h 
	gcc -g -c objBox.c

player.o : player.c player.h objBox.h
	gcc -g -c player.c objBox.c

ground.o : ground.c objBox.h
	gcc -g -c ground.c



#  @ prefix suppresses output of shell command
#  - prefix ignore errors
#  @command || true to avoid Make's error
#  : is shorthand for true
design :

clean :
	rm game enemy.o objBox.o player.o ground.o



