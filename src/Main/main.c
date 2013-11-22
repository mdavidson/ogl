/**	main.c
 ** Author: Mike and Alaska
 ** ver. 1.0
 ** This is the main loop for the OpenGL application.
 **/

#include <GLFW\glfw3.h>

#include "..\Callback\err_callbk.h"
#include "..\Callback\key_callbk.h"
#include "vid_init.h"
#include "..\Renderer\renderer.h"
#include "..\Game\game_control.h"

int main( int argc, char *argv[] )
{
    GLFWwindow* window;
    game_control_struct game_ctrl;

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
    Get and list video modes available to file
    */
    writeVidModes();

    /*
    Create a windowed mode window and its OpenGL context
    */
    window = glfwCreateWindow( WINDOW_WIDTH, WINDOW_HEIGHT, "Hello World", glfwGetPrimaryMonitor(), NULL );
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

    glfwTerminate();
    return( 0 );
}

