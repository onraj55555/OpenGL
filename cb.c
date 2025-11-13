#define CB_IMPLEMENTATION
#include "cb.h"

void build() {
    command_t * cmd = command_init(CC);
    command_add_source_file(cmd, "src/main.c");
    command_add_source_file(cmd, "src/glad.c");
    command_add_source_file(cmd, "src/debug.c");
    command_add_source_file(cmd, "src/io.c");
    command_add_source_file(cmd, "src/shader.c");
    command_add_source_file(cmd, "src/shape.c");
    command_add_source_file(cmd, "src/stb_image.c");
    command_add_source_file(cmd, "src/texture.c");
    command_add_include_dir(cmd, "include");
    command_add_dynamic_library(cmd, "glfw");
    command_add_dynamic_library(cmd, "GL");
    command_add_dynamic_library(cmd, "m");
    command_append(cmd, "-fmax-include-depth=300");
    command_set_output_file(cmd, "build/main");
    command_execute(cmd);
    if(command_get_exit_code(cmd) != 0) {
        printf("Cannot be compiled, probably forgot to pull in the external dependencies!\n");
        command_has_exited_normally(cmd);
    }
    command_deinit(cmd);
}

void run() {
    command_t * cmd = command_init("build/main");
    command_execute(cmd);
    command_has_exited_normally(cmd);
    command_deinit(cmd);
}

int main(int argc, char ** argv) {
    cb_rebuild_on_change(__FILE__, argv);
    parse_arguments(argc, argv);
    build();
    char * argument = argv[1];
    if(strcmp(argument, "run") == 0) run();
    return 0;
}
