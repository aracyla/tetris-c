#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "controller_tetris.h"
 
int main(void)
{
	pthread_t threads1, threads2;	
	int err;
	screen map;
	prepareMap(map);
	
	err = pthread_create(&threads1, NULL, (void*)readKeyboard, (void*)map);
	if (err)
	{	
		printf("Erro1\n");
		exit(1);
	}
	
	err = pthread_create(&threads2, NULL, (void*)controller, (void*)map);
	if (err != 0)
	{
		printf("Erro2\n");
		exit(1);
	}	
	pthread_join( threads1, NULL);
    pthread_join( threads2, NULL);


	return 0;
}





