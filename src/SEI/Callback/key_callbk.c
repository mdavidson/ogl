/** key_callbk.c
 ** Author: Alaska
 ** ver. 1.0
 ** This program uses the key_callback function and any other 
 ** necessary functions to process keyboard and mouse input to
 ** the OpenGL window.
 **/

#include <GLFW\glfw3.h>

#include "key_callbk.h"

void key_callback
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