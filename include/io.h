#ifndef IO_H_
#define IO_H_

#include "allocator.h"

char * read_entire_file(const char * path, allocator_t * a);

#endif
