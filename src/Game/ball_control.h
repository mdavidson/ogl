/*
    ball_control.h
*/
#ifndef __BALL_CONTROL_H
#define __BALL_CONTROL_H

#include "game_control.h"

#define BALL_HEIGHT    75.0f
#define BALL_WIDTH     75.0f


/*
*
*   ball_control.c functions
*
*
*/
void init_ball_posn
    (
    game_control_struct *game_ctrl
    );

void updt_ball_posn
    (
    game_control_struct *game_ctrl
    );

void render_ball
    (
    game_control_struct *game_ctrl
    );

#endif