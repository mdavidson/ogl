/** vid_init.c 
 ** Author: Alaska
 ** ver. 1.0
 ** This program is responsible for writing video modes to file
 ** so that it may be parsed by the default initialization for
 ** resolution and color bit setup.  Also initializes GLFW window.
 **/

#include <GLFW\glfw3.h>
#include <stdio.h>

#include "vid_init.h"
#include "..\Callback\err_callbk.h"
#include "..\Ball\game_control.h"
#include "..\Callback\key_callbk.h"
#include "..\Renderer\renderer.h"

int initGame(int argc, char *argv[])
{
    game_control_struct game_ctrl;
    GLFWwindow* window;

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
    {
        return -1;
    }

    writeVidModes();

    window = glfwCreateWindow( 1280, 1024, "Hello World", glfwGetPrimaryMonitor(), NULL );
    if (!window)
    {
        glfwTerminate();
        return 1;
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

    return 0;
}

void writeVidModes(void)
{
    int i;
    int count;
    FILE *fp; 
    const GLFWvidmode *ptr;

    fopen_s(&fp,"vidmodes.si", "w");
    if (&fp == NULL){
        error_callback(GLFW_INVALID_VALUE, "Could not open video modes!");
    }
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