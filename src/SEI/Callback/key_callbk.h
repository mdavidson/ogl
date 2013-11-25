#ifndef __KEY_CALLBK_H
#define __KEY_CALLBK_H

/** This function returns handles key callback
 ** for the OpenGL window.
 ** @return void    - no return value
 ** @param window   - a pointer to GLFWwindow, our window instance
 ** @param key      - an integer
 ** @param scancode - an integer
 ** @param action   - an integer
 ** @param mods      - an integer
 **/
void key_callback
    (
    GLFWwindow* window, 
    int key, 
    int scancode, 
    int action,
    int mods
    );

#endif