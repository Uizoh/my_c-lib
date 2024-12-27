#ifndef MY_QUEUE_
#define MY_QUEUE_

#include "my_defaults.h"

typedef struct Queue* Queue;

void enqueue(Queue self, int32_t item);
int32_t deque(Queue self);
int32_t peek(Queue self);


#endif
