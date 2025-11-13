#include "shape.h"

void shape_init(shape_t *shape) {
    shape->element_count = 0;
    glGenVertexArrays(1, &shape->VAO);
    glGenBuffers(1, &shape->VBO);
    glGenBuffers(1, &shape->EBO);
}

void shape_load_vertices(shape_t * shape, float * vertices, size_t vertices_size) {
    glBindVertexArray(shape->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, shape->VBO);

    glBufferData(GL_ARRAY_BUFFER, vertices_size, vertices, GL_STATIC_DRAW);

    //glBindVertexArray(0);
}

void shape_load_indices(shape_t * shape, unsigned int * indices, size_t indices_size) {
    glBindVertexArray(shape->VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, shape->EBO);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_size, indices, GL_STATIC_DRAW);

    //glBindVertexArray(0);

    shape->element_count = indices_size / sizeof(unsigned int);
}

void shape_interpret_and_enable(shape_t * shape ,unsigned int location, int vector_size, GLenum data_type, GLboolean normalised, size_t stride, void * offset_in_data) {
    glBindVertexArray(shape->VAO);

    glVertexAttribPointer(location, vector_size, data_type, normalised, stride, offset_in_data);
    glEnableVertexAttribArray(location);

    //glBindVertexArray(0);
}

void shape_draw(shape_t * shape) {
    glBindVertexArray(shape->VAO);
    glDrawElements(GL_TRIANGLES, shape->element_count, GL_UNSIGNED_INT, 0);
}
