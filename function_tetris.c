#include "function_tetris.h"

//fazer varredura por linhas, e arrasta-las por completo
void moveDownPiece(screen map)
{
	int idx, jdx;

	for(jdx = HEIGHT-1; jdx >= 0; jdx--)
	{
		for(idx = WIDTH-1; idx >= 0; idx--)
		{
			if(map[idx][jdx] == moving)
			{
				
				if((jdx == HEIGHT-1)||(map[idx][jdx+1] == idle))
					map[idx][jdx] = idle;	
					
				else
				{
					map[idx][jdx+1] = moving;
					map[idx][jdx] = dontCare;
				}
			}			
		}
		
	}
}


//======================================================================

void drawScreen(screen map)
{
	int idx, jdx;
	system("clear");
	for(jdx = 0; jdx < HEIGHT; jdx++)
	{
		for(idx = 0; idx < WIDTH; idx++)
		{
			printf("%d", map[idx][jdx]);
		}
		printf("\n");
	}
	 
}

//==================================================================

void prepareMap(screen map)
{
	int i, j;
	for(j = 0; j < HEIGHT; j++)
	{
		for(i = 0; i< WIDTH; i++)
		{
			map[i][j] = 0;
		}
	}
}

//===================================================================

pieceType newPiece()
{
	srand(time(NULL));
	return rand()%3;
}


//===================================================================

subtypeLine newLineType()
{
	srand(time(NULL));
	return rand()%2;
}

//===================================================================

subtypeL newLType()
{
	srand(time(NULL));
	return rand()%2+2;
}

//====================================================================

void eliminatePieces(screen map)
{
	boolean fullLine;
	int jdx, aux_jdx, idx;
	for(jdx = HEIGHT-1; jdx >= 0; jdx--)
	{
		
		fullLine = true;

		for(idx = WIDTH-1; idx >= 0; idx--)
		{
			if (map[idx][jdx] == 0)
				fullLine=false;
		}

		if(fullLine == true)
		{
			for(aux_jdx = jdx; aux_jdx >= 1; aux_jdx--)
				for(idx = WIDTH-1; idx >= 0; idx--)
					map[idx][aux_jdx] = map[idx][aux_jdx-1];
		}
	
	}
}

//====================================================================

void createPiece(pieceType piece, screen map)
{
	if(piece == shape)
	{
		map[WIDTH/2][0] = 1;
		map[WIDTH/2+1][0] = 1;
		map[WIDTH/2][1] = 1;
		map[WIDTH/2+1][1]= 1;
	}
	
	if(piece == line)
	{
		if (newLineType() == vLine)
		{			
			map[WIDTH/2][0] = 1;
			map[WIDTH/2][1] = 1;
			map[WIDTH/2][2] = 1;
			map[WIDTH/2][3] = 1;
		}
		
		if (newLineType() == hLine)
		{	
			map[WIDTH/2-1][0] = 1;
			map[WIDTH/2+1][0] = 1;
			map[WIDTH/2][0] = 1;
			map[WIDTH/2+2][0] = 1;
		}
	}
	
	if(piece == l)
	{
		if (newLType() == leftL)
		{
			map[WIDTH/2][0] = 1;
			map[WIDTH/2][1] = 1;
			map[WIDTH/2][2] = 1;
			map[WIDTH/2-1][2] = 1;
		}
		
		if (newLType() == rightL)
		{
			map[WIDTH/2][0] = 1;
			map[WIDTH/2][1] = 1;
			map[WIDTH/2][2] = 1;
			map[WIDTH/2+1][2] = 1;
		}
		
		if (newLType() == rightStep)
		{
			map[WIDTH/2-1][0] = 1;
			map[WIDTH/2][0] = 1;
			map[WIDTH/2+1][0] = 1;
			map[WIDTH/2-1][1] = 1;
		}
		
		
		if (newLType() == leftStep)
		{
			map[WIDTH/2-1][0] = 1;
			map[WIDTH/2][0] = 1;
			map[WIDTH/2+1][0] = 1;
			map[WIDTH/2+1][1] = 1;
		}
	}

}


//================================================================

pieceState anyPieceMoving(screen map)
{
	int i, j;
	for(j = 0; j < HEIGHT; j++)
	{
		for(i = 0; i< WIDTH; i++)
		{
			if(map[i][j] == moving)
				return moving;
		}
	}
	return dontCare;
}


//================================================================

int kbhit(void)
{
	struct termios oldt, newt;
	int ch;
	int oldf;
  
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
  
	ch = getchar();
  
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);
  
	if(ch != EOF)
	{
		ungetc(ch, stdin);
		return 1;
	}
  
	return 0;
}

//====================================================================

void pieceColision(screen map)
{
	int i, j = HEIGHT-1, auxIndexJ, auxIndexI;
	for(j = HEIGHT-1; j > -1; j--)
	{
		for(i = 0; i< WIDTH; i++)
		{
			if ( ((map[i][j] == moving)&&(map[i][j+1] == idle) ) || ((map[i][j] == moving)&& (j == HEIGHT - 1)) )
			{
				for(auxIndexJ = 0; auxIndexJ<HEIGHT; auxIndexJ++)
				{
					for(auxIndexI = 0; auxIndexI<WIDTH; auxIndexI++)
					{
						if(map[auxIndexI][auxIndexJ]==moving)
							map[auxIndexI][auxIndexJ] = idle;
					}
				}
			}
		}
	}
}

//====================================================================

pieceType getPiecetype(screen map)
{
	int i,j;
	for(j = 0; j < HEIGHT; j++)
	{
		for(i = 0; i< WIDTH; i++)
		{
			if( ( (map[i][j] == moving) && (map[i+1][j] == moving) && (map[i+2][j] == moving) && (map[i+3][j] == moving) ) || 
				( (map[i][j] == moving) && (map[i][j+1] == moving) && (map[i][j+2] == moving) && (map[i][j+3] == moving) ) )
			{
				printf("Line!");
				return line;
			}
		}
	}
	return l;
}

/*
 * 
 * 
 * 
 * testaColisão(), se sim, transforma 1 em 0
 * 
 * 
void inputTyped()
{
	//turn and esc
}



void newThing(screen map)
{
	map[10][0] = 1;
}
*/
