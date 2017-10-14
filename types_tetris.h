#define 	WIDTH				10
#define 	HEIGHT				25
#define		TRUE 				1
#define 	FALSE				0

typedef enum 
{
	dontCare = 0,
	moving = 1,
	idle = 2,
}pieceState; 

typedef enum
{
	shape,
	l,
	line,
}pieceType;

typedef enum
{
	vLine,
	hLine,
}subtypeLine;


typedef enum
{
	rightL,
	leftL,
	rightStep,
	leftStep,
}subtypeL;

typedef enum
{
	true,
	false,
}boolean;

typedef enum
{
	first,
	second,
	third,
	forth,
}pieceTurns;

typedef int screen[WIDTH][HEIGHT];
