#ifndef _VALIDATE_PROGRAM_
#define _VALIDATE_PROGRAM_ 

#include <iostream>
#include "GL/gl3w.h"

/*
    Call this on your program object after linking. It will pull the logs for 
    the object and print them if they exist. 

    Depends on GL3 already being intialized in the calling scope. 

    Joseph Dighton, Sept 2022 
*/

void validateProgram(GLuint program_name){

        GLint log_size; 
        glGetProgramiv(program_name, GL_INFO_LOG_LENGTH, &log_size);
        GLchar log_chars[log_size];
        glGetProgramInfoLog(program_name, log_size, NULL, log_chars);
        if(!(log_size == 0)){
            std::cout << log_chars << '\n';
        }
    }
#endif