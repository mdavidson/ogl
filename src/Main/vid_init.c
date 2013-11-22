/** vid_init.c 
 ** Author: Alaska
 ** ver. 1.0
 ** This program is responsible for writing video modes to file
 ** so that it may be parsed by the default initialization for
 ** resolution and color bit setup.
 **/

#include <GLFW\glfw3.h>
#include <stdio.h>

#include "vid_init.h"
#include "..\Callback\err_callbk.h"

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