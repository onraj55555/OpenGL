#ifndef SHADER_H_
#define SHADER_H_

#include <glad/glad.h>
#include "allocator.h"

typedef unsigned int shader_t;
typedef unsigned int shader_program_t;

shader_t shader_compile(shader_t shader_type, const char * path, allocator_t * a);
void shader_delete(shader_t shader);
shader_program_t shader_program_link(shader_t vertex_shader, shader_t fragment_shader);
void shader_program_use(shader_program_t program);
void shader_program_set_int(shader_program_t program, const char * name, int value);
void shader_program_set_2_int(shader_program_t program, const char * name, int value1, int value2);
void shader_program_set_3_int(shader_program_t program, const char * name, int value1, int value2, int value3);
void shader_program_set_4_int(shader_program_t program, const char * name, int value1, int value2, int value3, int value4);
void shader_program_set_unsigned_int(shader_program_t program, const char * name, unsigned int value);
void shader_program_set_2_unsigned_int(shader_program_t program, const char * name, unsigned int value1, unsigned int value2);
void shader_program_set_3_unsigned_int(shader_program_t program, const char * name, unsigned int value1, unsigned int value2, unsigned int value3);
void shader_program_set_4_unsigned_int(shader_program_t program, const char * name, unsigned int value1, unsigned int value2, unsigned int value3, unsigned int value4);
void shader_program_set_float(shader_program_t program, const char * name, float value);
void shader_program_set_2_float(shader_program_t program, const char * name, float value1, float value2);
void shader_program_set_3_float(shader_program_t program, const char * name, float value1, float value2, float value3);
void shader_program_set_4_float(shader_program_t program, const char * name, float value1, float value2, float value3, float value4);

#endif
