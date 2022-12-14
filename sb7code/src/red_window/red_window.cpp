#include "sb7.h"

/* 
    sb7::application defines an internal function 'run' that causes several other functions to 
    be called repeatedly in sequence, one of those is 'render' which we must define by virtue of
    it being an abstract (virtual) function 
*/ 

class my_application : public sb7::application{
public: 
    void render(double currentTime){
        static const GLfloat red[] = { 1.0f, 0.0f, 0.0f, 1.0f };
        glClearBufferfv(GL_COLOR, 0, red);

    }
};

DECLARE_MAIN(my_application); 