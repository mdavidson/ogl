/*
    ball_control.c
*/

#include <GLFW\glfw3.h>

#include "ball_control.h"
#include "game_control.h"

/*
*
*   init_ball_posn() - Initialize ball position
*
*/

void init_ball_posn
    (
    game_control_struct *game_ctrl
    )
{
game_ctrl->ball_x = 3.5f;
game_ctrl->ball_y = 1.5f;

game_ctrl->up = TRUE;
game_ctrl->right = TRUE;

}


/*
*
*   updt_ball_posn() - Update ball position
*
*/
void updt_ball_posn
    (
    game_control_struct *game_ctrl
    )
{
if( game_ctrl->right
 && ( game_ctrl->ball_x + 1 + BALL_WIDTH >= WINDOW_WIDTH ) )
    {
    game_ctrl->right = FALSE;
    }
else if( !game_ctrl->right 
      && ( game_ctrl->ball_x - 1 <= 0.0f ) ) 
    {
    game_ctrl->right = TRUE;
    }

if( game_ctrl->up
 && ( game_ctrl->ball_y + 1 + BALL_HEIGHT >= WINDOW_HEIGHT ) )
    {
    game_ctrl->up = FALSE;
    }
else if( !game_ctrl->up
      && ( game_ctrl->ball_y - 1 <= 0.0f ) )
    {
    game_ctrl->up = TRUE;
    }

if( game_ctrl->up )
    {
    game_ctrl->ball_y++;
    }
else
    {
    game_ctrl->ball_y--;
    }

if( game_ctrl->right )
    {
    game_ctrl->ball_x++;
    }
else
    {
    game_ctrl->ball_x--;
    }

}

/*
*
*   render_ball() - Render current ball position
*
*/
void render_ball
    (
    game_control_struct *game_ctrl
    )
{

glColor4f( 1.0, 1.0, 1.0, 0.0 );
glOrtho( 0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT, -1.0, 1.0 );
glBegin( GL_POLYGON );
        glVertex3f( game_ctrl->ball_x,                  game_ctrl->ball_y,                    0.0 );
        glVertex3f( game_ctrl->ball_x + BALL_WIDTH, game_ctrl->ball_y,                    0.0 );
        glVertex3f( game_ctrl->ball_x + BALL_WIDTH, game_ctrl->ball_y + BALL_HEIGHT, 0.0 );
        glVertex3f( game_ctrl->ball_x,                   game_ctrl->ball_y + BALL_HEIGHT, 0.0 );
glEnd();


}