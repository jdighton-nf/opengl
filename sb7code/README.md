OpenGL SuperBible 7th Edition Source Code
=========================================

This is the repository for the example source code for the 7th edition of the
OpenGL SuperBible. Please read HOWTOBUILD.txt. It tells you how to build and
run the examples.

*Note that to run these examples, you need the associated media files which
are available from http://openglsuperbible.com/files/superbible7-media.zip*.

You can't draw unless you have a VAO, VAOs can be attached to your contect with glBindVertexArray() 

GLDL provides a ton of built-in variables with various purposes.

One such example is glVertexID, which is provided to the vertex shader. When you call glDrawArrays, the second param
is the index of the vertex to start drawing..
You can define an arr of vertices in the vertex array if you want, which can then be cycled through automatically
as the gl_VertexID increments 
I am not entirely sure how to control gl_VertexID, or if I even need to. It seems as though it handled it automatically. 
Looking at glDrawArrays(first, number_to_draw) - there must be a relationship here between this call and glVertexID, 
so depending on how many must be drawn, glVertexID will interate throught the vertex shader for each. 

Chapter 3. Following the Pipeline
The vertex shader is the only mandatory part of the pipeline. 
