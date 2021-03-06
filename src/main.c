/*  BOBBY HOLLOWAY EDITING PLUS PLUS
    main.c
*/

#include <GLFW\glfw3.h>

#include <stdlib.h>
#include <stdio.h>

#include "game_control.h"

static void render_game
    (
    game_control_struct *game_ctrl
    );

static void error_callback
    (
    int error,
    const char* description
    );

static void key_callback
    (
    GLFWwindow* window, 
    int key, 
    int scancode, 
    int action,
    int mods
    );

/*
Master game control structure
*/
game_control_struct game_ctrl;


int main( int argc, char *argv[] )
{
    GLFWwindow* window;

    /*
    Setting error callback to receive any errors during
    initialization
    */
    glfwSetErrorCallback(error_callback);

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

    /*
    Set key callback to receive key events
    */
    glfwSetKeyCallback(window, key_callback);

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
    
    glfwDestroyWindow(window);
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

/*
*
*   error_callback
*
*
*/
static void error_callback
    (
    int error,
    const char* description
    )
{
fputs(description, stderr);

}

/*
*
*   key_callback
*
*
*/
static void key_callback
    (
    GLFWwindow* window, 
    int key, 
    int scancode, 
    int action,
    int mods
    )
{
switch( key )
    {
    case GLFW_KEY_ESCAPE:
        if( action == GLFW_PRESS )
            {
            glfwSetWindowShouldClose(window, GL_TRUE);
            }
        break;
    
    default:
        handle_game_key_press( &game_ctrl, key, scancode, action, mods );
        break;
    }
}
