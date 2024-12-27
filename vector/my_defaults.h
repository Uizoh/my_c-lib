#ifndef MY_DEFAULTS_
#define MY_DEFAULTS_


#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

#define len(arr) sizeof(arr) / sizeof(*arr)
#define randBetween(min, max) rand() % (max - min + 1) + min
#define dump(var) #var

typedef float float32_t;
typedef double float64_t;
typedef long double float128_t;
typedef const char* str;


#endif
