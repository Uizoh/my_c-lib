#ifndef MY_STACK_
#define MY_STACK_

#include "my_defaults.h"
#include <stdlib.h>


typedef struct Stack Stack;

Stack* newStack();
void push(Stack* self, int32_t item);
int32_t pop(Stack* self);
int32_t peek(Stack* self);
void freeStack(Stack* self);
uint32_t getStackLen(Stack* self);


#endif
