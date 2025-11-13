This is only for the vertex shader, data for fragment shader should be passed using 'in' and 'out' variables
The location of the vertex data send to the shader is specified with this:
```GLSL
layour (location = 0) in vec3 aPos;
```

Data is then interpreted and enabled as following:
```C
glVertexAttribPointer(location, vector_size, data_type, normalised, stride, offset_pointer);
glEnableVertexAttribArray(location);
```

- location is the location specified in the shader (location = 0)
- vector_size is the amount of element the vector has, 3 for vec3
- data_type is the type of data passed to the vector
- normalised, leave this false
- stride is the distance between data clusters
- offset is the offset from the start of the data stream the data for this location starts

Uniforms in GLSL can be specified in each of the shaders, do not need to be passed through the shader chain
```GLSL
uniform vec4 ourColour;
```
This is a uniform that specifies a float vector 4

In C, uniforms are then filled in as follows:
```C
glUseProgram(shader_program);
int uniform_location = glGetUniformLocation(shader_program, uniform_name);
glUniform4f(uniform_location, val1, val2, val3, val4);
```
