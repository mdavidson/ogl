#ifndef __ERR_CALLBK_H
#define __ERR_CALLBK_H

/** Function acts as error callback for OpenGL
 ** application.
 ** @return void - no return value
 ** @param error - appropriate error code type int
 ** @param description - string descript of problem
 **/
void error_callback
    (
    int error,
    const char* description
    );

#endif