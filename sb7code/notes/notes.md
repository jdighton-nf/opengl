OpenGl is an interface that your application can use to access the underlying graphics hardware. 

I think I need to camp on the pre-processor for a while: 
Lets say you have 3 files. main.cpp, engine.cpp, and car.cpp.

Possible that car.cpp might need to know about engines, so you might #include engine.cpp
The issue is that engine.cpp is already included in main. You you end up with a definition, which is not allowed. 
File guards prevent this unintended recursion from carrying on. 

When we were programming with Python and OpenGl we used a wrapper library called pyOpenGl, and another library called PyGame. 
PyGame provided us with usefull tools for loading and preparing images, as well as with the ability to handle input, have a window, sound etc. 

When working with C++ we use include GL/gl3w.h which is loads OpenGL, we also use GLFW/glfw3.h which provides utilities like windowing, input, etc. 

Pipelining and parallelism are the name of the game. 

Had to do a basic tutorial on Cmake because I have no idea what's going on. 
- Update, cmake now makes sense. 

Had to spend sometime reviewing the code for gl3w to understand what was happening. 
Basically it downloads to latest ARB header and loads pointers to all the OpenGl functions
using glXGetProcAddress()

Spend some time studying the code for the sb7 framework and it pretty well makes sense now. 
Simply put it does the following: 
-get glfw3 for handling windows, input, and context
-create the window
-make the window the current context
-load pointers to all the GL functions
-declare some basic functions 
-establish basic flow and gives us a template to work with 
-declare a pointer to an instance of an application which is a pure virtual, this
prevents a 'bare' instantiation. 

In our 'red_window' program I was introduced to 'glClearBufferfv()' the fv means that the functions
takes a vector of GLfloats. We specify the buffer name (GL_COLOR), the buffer number (0), and 
the array to pass it. 

Be VERY careful with your GLSL code because it FAILS SILENTLY and you'll spend 
a loooong time trying to unfuck it. 

example from today: (2 actually)

My render function (c++) didn't match the parent classes prototype
prototype : void render(double currentTime)
mine:       void render() - this won't be run 

Second: 

const vec4[] arr = vec4[](......)
^ is NOT the same as: 
const vec4[] arr = vec4(......)
This caused the shader to compile but not RUN and didn't throw an error. 

I was able to pass a VertexAttrib without defining the layout, not sure what to think 
of that. 

I spent a bunch of time reading about tesselation yesterday and this is what I've got. 

The vertex shader runs on batches of vertexs and provides groups of N vertices to the 
TCS as a patch. The TCS figures out how many control points to add or remove from the patch
and does so, it then passes the output patch to the tesselator. The tesselator does not
have access to the patch, but rather subdivides a primitive utilizing barycentric coords
and then passes this primitive to the TES. The TES takes the OP and the primitive and figures
out where to place new vertices as needed. This new geometry is what gets spit out of the 
entire tessalation phase. 

***The math chapter***

*The main input to OpenGL is the Vertex, which has a number of attributes that
normally includes a position*


