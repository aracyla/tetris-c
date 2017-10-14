#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include "types_tetris.h"


//=====================================================
//	move the pieces in the screen
// 	1 - the piece is moving
//  2 - the piece stop at some place 	
//=====================================================
void moveDownPiece(screen);


//===========================================================
//	draw the map on screen( at the moment with 0,1,2)
//===========================================================
void drawScreen(screen);


//=============================================================
//	Preset the map with 0
//==============================================================
void prepareMap(screen);


//===============================================================
//	Generate a random piece
//===============================================================
pieceType newPiece();

//===============================================================
//	Generate a subtype of a line
//===============================================================
subtypeLine newLineType();


//================================================================
//	eliminates a full line 
//================================================================
void eliminatePieces(screen);

//================================================================
//	add the piece to the map 
//================================================================
void createPiece(pieceType, screen);

//================================================================
//	return if there is a piece moving
//  1 - the piece is moving
//  2 - the piece stop at some place 	
//================================================================
pieceState anyPieceMoving(screen);

//
//
//
void pieceColision(screen);

//=================================================================
//	return the type of a piece
//================================================================
pieceType getPiecetype(screen);









//================================================================
//	Extern functions
//================================================================
int kbhit(void);



  
