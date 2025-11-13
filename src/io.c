#include "io.h"
#include <stdio.h>
#include "debug.h"

char * read_entire_file(const char * path, allocator_t * a) {
    FILE * f = fopen(path, "r");
    if(!f) panic("Failed to open file %s\n", path);

    fseek(f, 0, SEEK_END);
    long size = ftell(f) + 1;
    rewind(f);

    char * buffer = allocator_clean_alloc(a, size + 1, sizeof(char));
    fread(buffer, size, 1, f);
    buffer[size] = 0;

    fclose(f);

    return buffer;
} 
