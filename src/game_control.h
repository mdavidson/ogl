/*
    game_control.h
*/
#ifndef __GAME_CONTROL_H
#define __GAME_CONTROL_H

#include "types.h"


#define WINDOW_HEIGHT   720 
#define WINDOW_WIDTH    1280

typedef struct
    {
    /* 
        ball direction
    */
    boolean         up;
    boolean         right;
    /*
        ball position
    */
    float           ball_x;
    float           ball_y;

    /*
        Paddle positions
    */
    float           paddle_p1_x;
    float           paddle_p1_y;

    float           paddle_p2_x;
    float           paddle_p2_y;

    } game_control_struct;

/*
*
*   game_control.c functions
*
*
*/
void init_game_state
    (
    game_control_struct *game_ctrl
    );

void update_game_state
    (
    game_control_struct *game_ctrl
    );

void render_game_state
    (
    game_control_struct *game_ctrl
    );

#endif