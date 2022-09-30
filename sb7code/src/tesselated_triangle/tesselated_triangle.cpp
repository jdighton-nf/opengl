#include "sb7.h"

class tess_app : public sb7::application { 
public:
    // if a member function doesn't match the prototype in the parent class, it's not the same 
    void render(double currentTime){

        const GLfloat background[] = {  0.0f, 0.0f, 0.5f, 1.0 };
        const GLfloat offset[] = {
            (float)sin(currentTime) * 5.0f,
            (float)cos(currentTime) * 5.0f,
            1.0f, 
            1.0f
        };

        const GLfloat scaleFactor { 10 }; 

        glClearBufferfv(GL_COLOR, 0, background); 
        
        glVertexAttrib4fv(0, offset);
        glVertexAttrib1f(1, scaleFactor);

        glUseProgram(po);
        glDrawArrays(GL_TRIANGLES, 0, 3); 
    }
    void startup(){
        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // render in a wireframe mode
        po = load_program(); 
        printf("%i\n", po); 
        
    }
    void shutdown(){

    }
    GLuint load_program(); 
   
private:
    GLuint po; 
    GLuint vao;
};

GLuint tess_app::load_program(){
        // I am going to render a triangle now instead of a point 
         static const char* vs_src[] =
        {
            "#version 450 core                             					\n"
            "layout (location = 0) in vec4 offset;"
            "layout (location = 1) in float scaleFactor;            \n"
            "void main(void)                               			\n"
            "{                                             			\n"
            "   const vec4 vertices[] = vec4[]( vec4( 0.25, -0.25, 0.5, 1.0),      \n"
            "                                 vec4(-0.25, -0.25, 0.5, 1.0),     \n"
            "                                 vec4( 0.25,  0.25, 0.5, 1.0));      \n"
            "   gl_Position = (vertices[gl_VertexID] * scaleFactor) + offset;                     \n"
            "}                                             			\n"
        };

        static const char* fs_src[] =
        {
            "\
            #version 450 core\n\
            out vec4 color;\
            void main(void){\
                color = vec4(\
                            sin(gl_FragCoord.x * 0.25) * 0.5 + 0.5,\
                            cos(gl_FragCoord.y * 0.25) * 0.5 + 0.5, \
                            sin(gl_FragCoord.x * 0.25) * 0.5 + 0.5 * cos(gl_FragCoord.y * 0.15),\
                            1.0\
                            );\
            }\
            "
        };

        /*
            The TCS runs once per control point for a patch, the InvocationID is the 
            TCS index within the patch
            gl_TessLevelInner[edge_id] = subdivision_level
        */
        static const char* tcs_src[] =
        {
           
               " // Only if I am invocation 0 ...                                           \n"
               " if (gl_InvocationID == 0)                      \n"
               " {                      \n"
               " gl_TessLevelInner[0] = 5.0;                        \n"
               " gl_TessLevelOuter[0] = 5.0;                        \n"
               " gl_TessLevelOuter[1] = 5.0;                        \n"
               " gl_TessLevelOuter[2] = 5.0;                        \n"
               " }                      \n"
               " // Everybody copies their input to their output                        \n"
               " gl_out[gl_InvocationID].gl_Position =                      \n"
               " gl_in[gl_InvocationID].gl_Position;                        \n"
               " }                      \n"


        }; 

        static const char* tes_src[] = 
        {
            "#version 450 core                                                         \n"
            "layout (triangles, equal_spacing, cw) in;\n"
            "void main(void)\n"
            "{\n"
            "gl_Position = (gl_TessCoord.x * gl_in[0].gl_Position +\n"
            "gl_TessCoord.y * gl_in[1].gl_Position +\n"
            "gl_TessCoord.z * gl_in[2].gl_Position);\n"
            "}\n"

        };

        GLuint vs = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vs, 1, vs_src, NULL);
        glCompileShader(vs); 

        GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fs, 1, fs_src, NULL);
        glCompileShader(fs);

        GLuint tcs = glCreateShader(GL_TESS_CONTROL_SHADER);
        glShaderSource(tcs, 1, tcs_src, NULL);
        glCompileShader(tcs); 

        GLuint tes = glCreateShader(GL_TESS_EVALUATION_SHADER);
        glShaderSource(tes, 1, tes_src, NULL);
        glCompileShader(tes); 

        GLuint 

        po = glCreateProgram();
        glAttachShader(po, vs);
        glAttachShader(po, fs);
        // glAttachShader(po, tcs);
        // glAttachShader(po, tes);
        glLinkProgram(po);

        glDeleteShader(vs);
        glDeleteShader(fs); 
        glDeleteShader(tcs);
        glDeleteShader(tes); 

        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao); 

        return po; 
    }

DECLARE_MAIN(tess_app)