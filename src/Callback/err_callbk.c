/** err_callbk.c
 ** Author: Alaska
 ** ver. 1.0
 ** This program handles the error callback function and any
 ** other functions necessary for proper error handling for 
 ** the OpenGL window.
 **/

#include <stdio.h>

#include "err_callbk.h"

void error_callback
    (
    int error,
    const char* description
    )
{
    fputs(description, stderr);
}