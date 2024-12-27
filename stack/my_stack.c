#include "my_stack.h"
#include <stdlib.h>

typedef struct Node {
    int32_t value;
    struct Node* prev;
} *Node;

typedef struct Stack {
    uint32_t len;
    Node head;
} *Stack;

Stack newStack() {
    Stack tmp_stack = malloc(sizeof(struct Stack));
    assert(tmp_stack != NULL && "Unable to allocate memory for Stack");

    tmp_stack->len = 0;
    tmp_stack->head = NULL;

    return tmp_stack;
}

void pushStack()

