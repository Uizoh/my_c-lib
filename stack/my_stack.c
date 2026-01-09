#include "my_stack.h"

typedef struct Node {
    int32_t value;
    struct Node* prev;
} Node;

// Stack struct ponter
typedef struct Stack {
    uint32_t len;
    Node* head;
} Stack;

// Returns a new heap allocated Stack struct
Stack* newStack() {
    Stack* tmp_stack = malloc(sizeof(struct Stack));
    assert(tmp_stack != NULL && "Unable to allocate memory for Stack");

    tmp_stack->len = 0;
    tmp_stack->head = NULL;

    return tmp_stack;
}

// Add an item to a Stack
void push(Stack* self, int32_t item) {
    Node* tmp_node = malloc(sizeof(struct Node));
    assert(tmp_node != NULL && "Couldn't allocate memory for Node for Stack");

    tmp_node->value = item;
    tmp_node->prev = NULL;

    if (self->head == NULL) {
        self->head = tmp_node;
    } else {
        tmp_node->prev = self->head;
        self->head = tmp_node;
    }

    self->len += 1;
}

// Removes and frees a Node from the Stack head;
// Returns the value from the head node or returns NULL if head doesn't exist
int32_t pop(Stack* self) {
    if (self->head == NULL) {
        return (int32_t)NULL;
    }

    int32_t val = self->head->value;

    Node* tmp_head = self->head;
    self->head = self->head->prev;
    self->len -= 1;

    free(tmp_head);
    tmp_head = NULL;

    return val;
}

// Returns the value of head Node;
// Returns NULL if head doesn't exist
int32_t peek(Stack* self) {
    return self->head->value;
}

// Frees the whole Queue in memory
void freeStack(Stack* self) {
    while (self->head != NULL) {
        Node* tmp_head = self->head;
        self->head = self->head->prev;

        free(tmp_head);
        tmp_head = NULL;
    }

    free(self);
    self = NULL;
}

// Get the lenght of the Stack
uint32_t getStackLen(Stack* self) {
    return self->len;
}

