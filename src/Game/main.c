/**	main.c
 ** Author: Mike and Alaska
 ** ver. 1.0
 ** This is the main loop for the OpenGL application.
 **/

#include "..\SEI\Main\vid_init.h"

int main( int argc, char *argv[] )
{
    
	if ((initGame(argc, argv)) < 0)
		return -1;
	else
		return 0;

}

