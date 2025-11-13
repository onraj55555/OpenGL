#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "glad/glad.h"

typedef unsigned int texture_t;

void texture_init(texture_t * texture, const char * path);

#endif
