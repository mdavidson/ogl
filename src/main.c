/*  BOBBY HOLLOWAY EDITING PLUS PLUS
    main.c
*/

#include <GLFW\glfw3.h>

#include "game_control.h"


static void render_game
    (
    game_control_struct *game_ctrl
    );


int main( int argc, char *argv[] )
{
    GLFWwindow* window;
    game_control_struct game_ctrl;

    /*
    Initialize library
    */
    if( !glfwInit() ) {
        return( -1 );
        }

    /*
    Create a windowed mode window and its OpenGL context
    */
    window = glfwCreateWindow( WINDOW_WIDTH, WINDOW_HEIGHT, "Hello World", NULL, NULL );
    if( !window ) {
        glfwTerminate();
        return( -1 );
        }

    /*
    Make the window's context current
    */
    glfwMakeContextCurrent( window );

    /*
    Initialize game state
    */
    init_game_state( &game_ctrl );

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        update_game_state( &game_ctrl );
        render_game( &game_ctrl );

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return( 0 );
}


/*
*
*   render_game()
*
*
*/
static void render_game
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
