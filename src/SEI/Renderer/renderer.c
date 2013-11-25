/** renderer.c
 ** Author: Alaska
 ** ver. 1.0
 ** This program controls the primitive rendering of the OpenGL app.
 **/

#include <GLFW\glfw3.h>

#include "renderer.h"

void render_game
    (
    game_control_struct *game_ctrl
    )
{
glLoadIdentity();

glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
glClear( GL_COLOR_BUFFER_BIT );

render_game_state( game_ctrl );

glFlush();

}