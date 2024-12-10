#ifndef MY_VECTOR_
#define MY_VECTOR_


#include "my_defaults.h"

// For using in Vector struct creation with appropriate types
typedef enum TypeVec { INT, UINT, FLOAT } TypeVec;

// Vector struct pointer
typedef struct Vec {
    uint32_t len;
    uint32_t capacity;
    TypeVec type;
    union {
        int32_t* _arr_i;
        uint32_t* _arr_u;
        float64_t* _arr_f;
    };
} *Vec;

// Related functions
Vec newVec(TypeVec type, uint32_t init_cap);
void appendVec(Vec self, void* item);
void* sliceVec(Vec self, uint32_t starting_index, uint32_t last_index);
void freeVec(Vec self);

#endif
