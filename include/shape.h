#ifndef SHAPE_H_
#define SHAPE_H_

#include "glad/glad.h"
#include <stddef.h>

typedef struct shape_t shape_t;

struct shape_t {
    unsigned int element_count;
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
};

void shape_init(shape_t * shape);
void shape_load_vertices(shape_t * shape, float * vertices, size_t vertices_size);
void shape_load_indices(shape_t * shape, unsigned int * indices, size_t indices_size);
void shape_interpret_and_enable(shape_t * shape ,unsigned int location, int vector_size, GLenum data_type, GLboolean normalised, size_t stride, void * offset_in_data);
void shape_draw(shape_t * shape);

#endif
