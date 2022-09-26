#include "sb7.h"

class my_application : public sb7::application { 
public: 
    void render(double currentTime){

    }
};

GLuint compile_shader(void){
    GLuint vertex_shader;
    GLuint fragment_shader;
    GLuint program;

    static const GLchar* vertex_shader_source[] = {
        "#version 450 core                          \n",
        "void main(void){                           \n",
        "{                                          \n",
        "   gl_Position = vec4(0.0, 0.0, 0.5, 1.0); \n",
        "}                                          \n"
    }; 
    static const GLchar* fragment_shader_source[] = {
        "#version 450 core                          \n",
        "out vec4 color;                            \n",
        "void main(void)                            \n",
        "{                                          \n",
        "    color = vec4(0.0, 0.8, 1.0, 1.0);      \n",
        "}                                          \n",
    };
    
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
    glCompileShader(vertex_shader);

    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
    glCompileShader(fragment_shader);

    program = glCreateProgram(); 
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    glDeleteShader(vertex_shader); 
    glDeleteShader(fragment_shader);

    return program; 
}

DECLARE_MAIN(my_application);