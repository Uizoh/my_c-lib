#ifndef MY_VECTOR_
#define MY_VECTOR_

#include "my_defaults.h"


typedef enum TypeVec TypeVec;
typedef struct Vec* Vec;

Vec newVec(TypeVec type, uint32_t init_cap);
void appendVec(Vec self, void* item);
void* sliceVec(Vec self, uint32_t starting_index, uint32_t last_index);
void popVec(Vec self, uint32_t index);
void freeVec(Vec self);
uint32_t getVecLen(Vec self);
uint32_t getVecCap(Vec self);
uint32_t getVecType(Vec self);


#endif
