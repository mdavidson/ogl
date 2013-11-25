#ifndef __VID_INIT_H
#define __VID_INIT_H

/** Function for writing avail vid modes
/*  to file.
/*  @return void - no return value
/*  @param void - no parameter
*/
void writeVidModes(void);

/** Function called by game to initialize
/*  engine and window.
/*  @return int - return 0 if no error
/*  @param argc - argument count from cmd line
/*  @param argv - argument vector from cmd line
*/
int initGame(int argc, char *argv[]);

#endif