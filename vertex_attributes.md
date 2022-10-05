**Vertex Attributes** 

*We don't want to have to hardcode our vertices into the shader. So there has to be a smarter way to feed them to the shaders.*

```
// The vertices are provided to the shaders by the vertex fetch stage. This is basically the VAO

GLuint vao;                     // create handle for vao 
glCreateVertexArrays(1, &vao);  // create vao
glBindVertexArray(vao);         // bind vao to context
```

glVertexArrayAttribBinding() - tells OpenGL that when vao is bound, that the indexed attrib should source it's data from the specified binding index. 

glVertexArrayVertexBuffer() - binds a buffer to one of the to one of the vertex buffer bindings 

glVertexArrayAttribFormat() - describes layout and format of data 

glEnableVertexAttribArray() - enable automatic filling of the data 

vao - the currently bound vao
bindingindex - 
attribindex - index of the vertex attr. You can define a large number of vertex attributes and then refer to them by their index. 
vbo - buffer buffer object 