/** game_control.c
 ** Author: Mike
 ** ver. 1.0
 ** This program is responsible for updating the gamestate.
 **/

#include <GLFW\glfw3.h>

#include "ball_control.h"
#include "game_control.h"

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
updt_ball_posn( game_ctrl );

}


void render_game_state
    (
    game_control_struct *game_ctrl
    )
{
render_ball( game_ctrl );

}