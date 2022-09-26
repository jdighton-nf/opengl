#include "sb7.h"

/* 
    sb7::application defines an internal function 'run' that causes several other functions to 
    be called repeatedly in sequence, one of those is 'render' which we must define by virtue of
    it being an abstract (virtual) function 
*/ 

class my_application : public sb7::application{
public: 
    void render(double currentTime){
        const GLfloat color[] = { 
                (float) sin (currentTime) * 0.5f + 0.5f, 
                (float) cos (currentTime) * 0.5f + 0.5f, 
                0.0f, 
                1.0f
            };
            printf("%d\n", ((float) sin (currentTime) * 0.5f + 0.5f)); 
        glClearBufferfv(GL_COLOR, 0, color);

    }
};

DECLARE_MAIN(my_application); 