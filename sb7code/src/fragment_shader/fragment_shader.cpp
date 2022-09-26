#include "sb7.h"

/*
    In this example I have to put the shader code inline with the c++ source file, which I do not like at all. 
    In the future I would like to find a way to have the fragment shader object pre-compiled and linked so that 
    we can just use it at runtime directly. 
*/



// basically 

class my_app : public sb7::application { 
public:    
    // shader code
    void init()
    {
        static const char title[] = "OpenGL SuperBible - Single Triangle";

        sb7::application::init();

        memcpy(info.title, title, sizeof(title));
    }
    GLuint compile_shaders(void){
        GLuint vertex_shader; 
        GLuint fragment_shader; 
        GLuint program; 

        static const char * vertex_shader_source[] =
        {
            "#version 420 core                                                 \n"
            "                                                                  \n"
            "layout (location = 0) in vec4 offset;                             \n"
            "layout (location = 1) in vec4 color_attr; \n"
            "out vec4 vs_color;\n"
            "void main(void)                                                   \n"
            "{                                                                 \n"
            "    const vec4 vertices[] = vec4[](vec4( 0.25, -0.25, 0.5, 1.0),  \n"
            "                                   vec4(-0.25, -0.25, 0.5, 1.0),  \n"
            "                                   vec4( 0.25,  0.25, 0.5, 1.0)); \n"
            "    vs_color = color_attr;                                         \n"
            "    gl_Position = vertices[gl_VertexID] + offset;                 \n"
            "}                                                                 \n"
        };
        static const char * fragment_shader_source[] =
        {
            "#version 420 core                                                 \n"
            "in vec4 vs_color;                                                 \n"
            "out vec4 color;                                                   \n"
            "                                                                  \n"
            "void main(void)                                                   \n"
            "{                                                                 \n"
            "    color = vs_color;                             \n"
            "}                                                                 \n"
        };

        // compile vertex shader
        vertex_shader = glCreateShader(GL_VERTEX_SHADER); 
        glShaderSource(vertex_shader, 1, vertex_shader_source, NULL); 
        glCompileShader(vertex_shader); 
        // compile fragment shader
        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER); 
        glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
        glCompileShader(fragment_shader); 
        // create and link GL program 
        program = glCreateProgram();
        glAttachShader(program, vertex_shader);
        glAttachShader(program, fragment_shader);
        glLinkProgram(program);
        // delete now uneeded shader objects
        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);

        // the program is referenced by a GLuint, which is just a number that OpenGL can use to find it 
        return program; 
    }
    void startup(){
        glPointSize(40.0f);
        rendering_program = compile_shaders();   
        glGenVertexArrays(1, &vertex_array_object);      // create our VAO
        glBindVertexArray(vertex_array_object);             // bind VAO to current context
    }
    void shutdown(){
        glDeleteVertexArrays(1, &vertex_array_object);
        glDeleteProgram(rendering_program);
        glDeleteVertexArrays(1, &vertex_array_object); 
    }
    void render(double currentTime){

        const GLfloat color[] = { 0.5f, 0.0f, 0.0f, 1.0f };
        
        GLfloat pos_attrib[] = {
            (float)sin(currentTime) * 0.5f,
            (float)cos(currentTime) * 0.5f,
            0.0f,
            0.0f
        };
        GLfloat color_attrib[] = {
            0.0f,
            (float) cos (currentTime) * 0.5f + 0.5f,
            (float) sin (currentTime) * 0.5f + 0.5f,
            1.0f
        }; 


        glVertexAttrib4fv(0, pos_attrib);
        glVertexAttrib4fv(1, color_attrib);

        glClearBufferfv(GL_COLOR, 0, color);
        
        // use the program object we created
        glUseProgram(rendering_program); 
        // draw a single triangle, the parameters on this are critical because they MUST be correct
        glDrawArrays(GL_TRIANGLES, 0, 3); 
    }

private:
    GLuint rendering_program;
    GLuint vertex_array_object; 
}; 

DECLARE_MAIN(my_app); 