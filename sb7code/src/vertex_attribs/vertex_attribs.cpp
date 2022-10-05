#include "sb7.h"
#include "vmath.h"
#include "validate_program.h" 
#include <iostream>

class a : public sb7::application { 
public:    
  
    void startup(){

        // load shaders
        program_object = { loadProgram() };
        
        // create vao
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        
        // create a buffer and give it our vertex data
        int n { 1 }; // create 1 buffer
        int size { 1024 };
        GLuint (*buffer_arr[]) { new GLuint[n] };
        glCreateBuffers(n, *buffer_arr); 
        glNamedBufferStorage(*buffer_arr[0], size, NULL, GL_DYNAMIC_STORAGE_BIT);
        glBindBuffer(GL_ARRAY_BUFFER, *buffer_arr[0]);

        static const float vertex_data[]{
        0.0, 0.0, 0.0, 1.0
        };

        glNamedBufferSubData(*buffer_arr[0], 0, size, &vertex_data);

        // set up vertex array attribs

        // 
        glVertexArrayVertexBuffer(vao, 0, *buffer_arr[0], 0, sizeof(vmath::vec4));
        
        glVertexArrayAttribFormat(vao, 0, 4, GL_FLOAT, GL_FALSE, 0);
        
        glEnableVertexArrayAttrib(vao, 0); 
        buffers = *buffer_arr; 
   }
  
    void shutdown(){

    }
  
    GLuint loadProgram(){
        const GLchar* vs_src[] {
            "#version 450 core \n"
            // there seems to be something in location 0 by default
            "layout (location = 0) in vec4 position;"
            "void main(void){"
            "   gl_Position = position;"
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

    void render(double currentTime){
        const GLfloat color[] {
            0.0f, 0.2f, 0.2f, 1.0f
        };

        const GLfloat vertex_data[]{
            (float) cos(currentTime) * 0.75f,
            (float) sin(currentTime) * 0.75f, 
            0.0, 
            1.0,
            (float) cos(currentTime) * 0.50f,
            (float) sin(currentTime) * 0.50f, 
            0.0, 
            1.0,
            (float) cos(currentTime) * 0.25f,
            (float) sin(currentTime) * 0.25f, 
            0.0, 
            1.0
        };

        // strangely enough this is allowed
        glNamedBufferSubData(buffers[0], 0, 1024, &vertex_data); 

        glClearBufferfv(GL_COLOR, 0, color);
        glUseProgram(program_object);
        const GLuint (*indices[]) {new GLuint[3]{0, 1, 2}}; 
        glDrawArrays(GL_POINTS, 0, 3);
        
    }
private:
    GLuint program_object;
    GLuint vao; 
    GLuint* buffers; // buffer array on the free store 
};

DECLARE_MAIN(a)