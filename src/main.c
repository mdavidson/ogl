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

static void writeVidModes(void);

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
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

/*
*
*   writeVidModes
*
*/
static void writeVidModes(void)
{
    int i;
    int count;
    FILE *fp; 
    const GLFWvidmode *ptr;

    fopen_s(&fp,"vidmodes.si", "w");
    if (&fp == NULL)
        error_callback(GLFW_INVALID_VALUE, "Could not open video modes!");
    else{
        ptr = glfwGetVideoModes(glfwGetPrimaryMonitor(), &count);

        i = 0;
        while (i < count){
            fprintf(fp, "-//MODE %d //- \n", i);
            fprintf(fp, "%d R\n", ptr[i].redBits);
            fprintf(fp, "%d G\n", ptr[i].greenBits);
            fprintf(fp, "%d B\n", ptr[i].blueBits);
            fprintf(fp, "%d px\n", ptr[i].height);
            fprintf(fp, "%d px\n", ptr[i].width);
            fprintf(fp, "%d Hz\n", ptr[i].refreshRate);
            i++;
        }

        fclose(fp);
    }
}

