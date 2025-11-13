#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#define ALLOCATOR_HEAP_ALLOCATOR
#include "allocator.h"
#include "shader.h"
#include "shape.h"
#include "math.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void framebuffer_size_callback(GLFWwindow * window, int width, int height) {
    glViewport(0, 0, width, height);
}

void process_input(GLFWwindow * window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, 1);
    }
}

void make_square(shape_t * square, float * vertices, size_t vertices_size, unsigned int * indices, size_t indices_size, shader_program_t * program, const char * vertex_path, const char * fragment_path, allocator_t * a) {
    shape_init(square);
    shape_load_vertices(square, vertices, vertices_size);
    shape_load_indices(square, indices, indices_size);
    shape_interpret_and_enable(square, 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

    shader_t vertex_shader = shader_compile(GL_VERTEX_SHADER, vertex_path, a);
    shader_t fragment_shader = shader_compile(GL_FRAGMENT_SHADER, fragment_path, a);
    *program = shader_program_link(vertex_shader, fragment_shader);
}

void make_colourful_triangle(shape_t * square, float * vertices, size_t vertices_size, unsigned int * indices, size_t indices_size, shader_program_t * program, const char * vertex_path, const char * fragment_path, allocator_t * a) {
    shape_init(square);
    shape_load_vertices(square, vertices, vertices_size);
    shape_load_indices(square, indices, indices_size);
    shape_interpret_and_enable(square, 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    shape_interpret_and_enable(square, 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));

    shader_t vertex_shader = shader_compile(GL_VERTEX_SHADER, vertex_path, a);
    shader_t fragment_shader = shader_compile(GL_FRAGMENT_SHADER, fragment_path, a);
    *program = shader_program_link(vertex_shader, fragment_shader);
}


int main() {
    // OpenGL setup
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow * window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Title", NULL, NULL);
    if(!window) {
        printf("Failed to create window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialise GLAD\n");
        glfwTerminate();
        return -1;
    }

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glfwSetWindowSizeCallback(window, framebuffer_size_callback);
    // End of OpenGL setup

    allocator_t a;
    allocator_new_heap_allocator(&a);

    float vertices[] = {
        0.5f, 0.5f, 0.0f, // top right
        0.5f, -0.5f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f // top left
    };

    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    float colour_vertices[] = {
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f
    };

    unsigned int colour_indices[] = {
        0, 1, 2
    };


    shape_t shape;
    shader_program_t program;
    //make_square(&shape, vertices, sizeof(vertices), indices, sizeof(indices), &program, "shaders/simple_vertex.glsl", "shaders/simple_fragment.glsl", &a);
    make_colourful_triangle(&shape, colour_vertices, sizeof(colour_vertices), colour_indices, sizeof(colour_indices), &program, "shaders/colourful_vertex.glsl", "shaders/colourful_fragment.glsl", &a);

    while(!glfwWindowShouldClose(window)) {
        // Process input
        process_input(window);

        // Render
        glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader_program_use(program);

        //float time_value = glfwGetTime();
        //float green_value = sin(time_value) / 2.0f + 0.5f;
        //shader_program_set_4_float(program, "ourColour", 0.0f, green_value, 0.0f, 1.0f);
        //glBindVertexArray(VAO);
        //glDrawArrays(GL_TRIANGLES, 0, 3);
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        shape_draw(&shape);
        glBindVertexArray(0);

        // Check and call events and swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
