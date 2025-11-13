#include "shader.h"
#include "io.h"
#include "debug.h"
#include <stdio.h>

shader_t shader_compile(GLenum shader_type, const char * path, allocator_t * a) {
    shader_t shader = glCreateShader(shader_type);
    const char * shader_source = read_entire_file(path, a);
    glShaderSource(shader, 1, &shader_source, NULL);
    glCompileShader(shader);
    allocator_free(a, (void*)shader_source);

    int success;
    char info_log[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success) {
        char * type = 0;
        if(GL_VERTEX_SHADER == shader_type) type = "GL_VERTEX_SHADER";
        else if(GL_FRAGMENT_SHADER == shader_type) type = "GL_FRAGMENT_SHADER";
        glGetShaderInfoLog(shader, 512, NULL, info_log);
        panic("Shader compile error for shader type %s: %s\n", type, info_log);
    }

    return shader;
}

void shader_delete(shader_t shader) {
    glDeleteShader(shader);
}

shader_program_t shader_program_link(shader_t vertex_shader, shader_t fragment_shader) {
    shader_program_t program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    int success;
    char info_log[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(program, 512, NULL, info_log);
        panic("Shader link error: %s\n", info_log);
    }

    return program;
}

void shader_program_use(shader_program_t program) {
    glUseProgram(program);
}

void shader_program_set_int(shader_program_t program, const char * name, int value) {
    shader_program_use(program);
    int location = glGetUniformLocation(program, name);
    glUniform1i(location, value);
}

void shader_program_set_2_int(shader_program_t program, const char * name, int value1, int value2) {
    shader_program_use(program);
    int location = glGetUniformLocation(program, name);
    glUniform2i(location, value1, value2);
}

void shader_program_set_3_int(shader_program_t program, const char * name, int value1, int value2, int value3) {
    shader_program_use(program);
    int location = glGetUniformLocation(program, name);
    glUniform3i(location, value1, value2, value3);
}

void shader_program_set_4_int(shader_program_t program, const char * name, int value1, int value2, int value3, int value4) {
    shader_program_use(program);
    int location = glGetUniformLocation(program, name);
    glUniform4i(location, value1, value2, value3, value4);
}

void shader_program_set_unsigned_int(shader_program_t program, const char * name, unsigned int value) {
    shader_program_use(program);
    int location = glGetUniformLocation(program, name);
    glUniform1ui(location, value);
}

void shader_program_set_2_unsigned_int(shader_program_t program, const char * name, unsigned int value1, unsigned int value2) {
    shader_program_use(program);
    int location = glGetUniformLocation(program, name);
    glUniform2ui(location, value1, value2);
}

void shader_program_set_3_unsigned_int(shader_program_t program, const char * name, unsigned int value1, unsigned int value2, unsigned int value3) {
    shader_program_use(program);
    int location = glGetUniformLocation(program, name);
    glUniform3ui(location, value1, value2, value3);
}

void shader_program_set_4_unsigned_int(shader_program_t program, const char * name, unsigned int value1, unsigned int value2, unsigned int value3, unsigned int value4) {
    shader_program_use(program);
    int location = glGetUniformLocation(program, name);
    glUniform4ui(location, value1, value2, value3, value4);
}

void shader_program_set_float(shader_program_t program, const char * name, float value) {
    shader_program_use(program);
    int location = glGetUniformLocation(program, name);
    glUniform1f(location, value);
}

void shader_program_set_2_float(shader_program_t program, const char * name, float value1, float value2) {
    shader_program_use(program);
    int location = glGetUniformLocation(program, name);
    glUniform2f(location, value1, value2);
}

void shader_program_set_3_float(shader_program_t program, const char * name, float value1, float value2, float value3) {
    shader_program_use(program);
    int location = glGetUniformLocation(program, name);
    glUniform3f(location, value1, value2, value3);
}

void shader_program_set_4_float(shader_program_t program, const char * name, float value1, float value2, float value3, float value4) {
    shader_program_use(program);
    int location = glGetUniformLocation(program, name);
    glUniform4f(location, value1, value2, value3, value4);
}


