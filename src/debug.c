#include "debug.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void panic(const char * fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "[PANIC] ");
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    exit(EXIT_FAILURE);
}
