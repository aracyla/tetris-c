#include "controller_tetris.h"
//========================================================

void turn(screen map, pieceTurns postion)
{	
	
	
}

//========================================================

void moveLeft(screen map)
{
	//mudar a movimentação
	int idx, jdx;
	boolean screenBoard;
	screenBoard = false;
	for(jdx = HEIGHT-1; jdx >= 0; jdx--)
	{
		for(idx = WIDTH-1; idx >= 0; idx--)
		{
			if((map[idx][jdx] == moving)&& ((idx == 0)||(map[idx-1][jdx] == 2)) )
				screenBoard = true;				
		}
	}
	
	for(jdx = HEIGHT-1; jdx >= 0; jdx--)
	{		
		for(idx = 0; idx < WIDTH; idx++)
		{
			if((map[idx][jdx] == moving)&&(screenBoard==false))
			{
				map[idx-1][jdx]=map[idx][jdx];
				map[idx][jdx]=0;
			}		
		}
	}
}

//=========================================================

void moveRight(screen map)
{
	int idx, jdx;
	boolean screenBoard;
	screenBoard = false;
	for(jdx = HEIGHT-1; jdx >= 0; jdx--)
	{
		for(idx = WIDTH-1; idx >= 0; idx--)
		{
			if((map[idx][jdx] == moving)&& ((idx == WIDTH-1)||(map[idx+1][jdx] == 2)) )
				screenBoard = true;				
		}
	}
	
	for(jdx = HEIGHT-1; jdx >= 0; jdx--)
	{		
		for(idx = WIDTH-1; idx >= 0; idx--)
		{
			if((map[idx][jdx] == moving)&&(screenBoard==false))
			{
				map[idx+1][jdx]=map[idx][jdx];
				map[idx][jdx]=0;
			}		
		}
	}
	
}

//=========================================================

void* readKeyboard(screen map)
{
	char keyDown;
	while(TRUE)
	{
		if(kbhit())
		{
			keyDown = getchar();
			//printf("%d\n\n\n", keyDown);			
			switch(keyDown)
			{
				case 'd':
					moveRight(map);
					drawScreen(map);
					break;
				case 'a':
					moveLeft(map);
					drawScreen(map);
					break;
				case 27:
					exit(2);
			}
		}
	}
}

//==========================================================

void* controller(screen map)
{
	while(TRUE)
	{
		if(anyPieceMoving(map) == dontCare)
		{
			createPiece(newPiece(), map);
		}
		pieceColision(map);
		moveDownPiece(map);
		drawScreen(map);
		eliminatePieces(map);
		
		
		usleep(350000);
	}

}

//===========================================================


