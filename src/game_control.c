/*
    game_control.c
*/

#include <GLFW\glfw3.h>

#include "game_control.h"
#include "ball_control.h"

void init_game_state
    (
    game_control_struct *game_ctrl
    )
{
init_ball_posn( game_ctrl );

}

void update_game_state
    (
    game_control_struct *game_ctrl
    )
{
//updt_ball_posn( game_ctrl );

}


void render_game_state
    (
    game_control_struct *game_ctrl
    )
{
render_ball( game_ctrl );

}

void handle_game_key_press
    (
    game_control_struct *game_ctrl,
    int key, 
    int scancode, 
    int action,
    int mods
    )
{
switch( key )
    {
    case GLFW_KEY_UP:    
    case GLFW_KEY_DOWN:        
    case GLFW_KEY_LEFT:
    case GLFW_KEY_RIGHT:
        move_ball_posn( game_ctrl, key );
        break;
    }

}