#include "sb7.h"

class tess_app : public sb7::application { 
public:
    void render(){
        static const GLchar vs[] = {
            "#version 450 core \ 
            layout (location = 0 ) in vec4 color; \
            layout (location = 1)  in vec4 offset; \
            out vec4 vs_color; \ 
            vec4[] vertices = (  \
                vec4(0.5f, 0.0f, 0.0f, 1.0f), \
                vec4(0.0f, 0.5f, 0.0f, 1.0f), \
                vec4(0.0f, 0.0f, 0.5f, 1.0f)  \
            ); \
            void main(void){ \
                vs_color = color; \ 
                gl_Position = vertices * offset;  \
            } \
            "
        };

        static const GLchar fs[] = {
            "#version 450 core \
            in vec4 color_from_vs; \
            "
        }
    }
    void startup(){

    }
    void shutdown(){

    }
    GLint load_program(){
        return 3; 
    }
private:
    GLint po; 
    GLint vao;
};

DECLARE_MAIN(tess_app)