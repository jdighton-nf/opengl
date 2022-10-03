#include "sb7.h"
#include "validate_program.h" 
#include <iostream>

class a : public sb7::application { 
public:    
  
    void startup(){
        glPointSize(40.0f); 
        program_object = { loadProgram() };
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        buffers  = { bufferMagic() }; 
    
   }
  
    void shutdown(){

    }
  
    GLuint loadProgram(){
        const GLchar* vs_src[] {
            "#version 450 core \n"
            "void main(void){"
            "   gl_Position = vec4(0.0, 0.0, 0.5, 1.0);"
            "}"
        };
        const GLchar* fs_src[] {
            "#version 450 core \n"
            "out vec4 color;"
            "void main(void){"
            "   color = vec4(1.0, 1.0, 1.0, 1.0);"
            "}"
        };
        const GLuint vs { glCreateShader(GL_VERTEX_SHADER) }; 
        const GLuint fs { glCreateShader(GL_FRAGMENT_SHADER) };
        glShaderSource(vs, 1, vs_src, nullptr);
        glCompileShader(vs);
        glShaderSource(fs, 1, fs_src, nullptr);
        glCompileShader(fs);
        GLuint po { glCreateProgram() };
        glAttachShader(po, vs);
        glAttachShader(po, fs);
        glLinkProgram(po);
        validateProgram(po);
        return po; 

        /*
            Additional lessons learned from today: If you forget to compile your shaders 
            before linking, you are going to have a bad time. Many of my problems have 
            been due to forgetting / missing a detail when linking programs. 

            These will fail silently unless you have a function to validate them. I've 
            written "void validate_program(GLuint program_name)" which will be called after
            linking ALWAYS. Its job is to notify me when something goes wrong. 
        */
    }
  
    GLuint* bufferMagic();

    void render(double currentTime){
        const GLfloat color[] {
            0.0f, 0.2f, 0.2f, 1.0f
        };
        glClearBufferfv(GL_COLOR, 0, color);
        glUseProgram(program_object);
        glDrawArrays(GL_POINTS, 0, 1);
    }
private:
    GLuint program_object;
    GLuint vao; 
    GLuint* buffers; 
};

GLuint* a::bufferMagic(){
    int n { 1 }; 
    /*
        my segfault was due to creating an array to pointers to GLuints, instead of a pointer
        to an array of GLuints 
    */
    GLuint (*buffer_arr[]) { new GLuint[n] }; 
    glCreateBuffers(n, *buffer_arr); 
    glNamedBufferStorage(*buffer_arr[0], 64, NULL, GL_DYNAMIC_STORAGE_BIT);
    glBindBuffer(GL_ARRAY_BUFFER, *buffer_arr[0]);

    static const float data[]{
        0.25, -0.25, 0.5, 1.0,
       -0.25, -0.25, 0.5, 1.0,
        0.25,  0.25, 0.5, 1.0
    };
    
    // ask OpenGL to write the data
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(data), data);

    return buffers; 
}

DECLARE_MAIN(a)