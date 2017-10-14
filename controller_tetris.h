#include "function_tetris.h"

//================================================================
//	Functions - user moves
//================================================================
void *readKeyboard(screen);
void moveRight(screen);
void moveLeft(screen);
void turn(screen, pieceTurns);

//================================================================
//	Independent moves
//================================================================
void *controller(screen);
