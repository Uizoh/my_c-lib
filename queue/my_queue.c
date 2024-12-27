#include "my_queue.h"
#include <stdlib.h>


typedef struct Node {
    int32_t value;
    struct Node* next;
} *Node;

// Queue struct
typedef struct Queue {
    uint32_t len;
    Node head;
    Node tail;
} *Queue;

// Creates and returns a heap allocated Queue struct
Queue newQueue() {
    Queue tmp_queue = malloc(sizeof(struct Queue));
    assert(tmp_queue != NULL && "Queue failed to be allocated in memory");

    tmp_queue->len = 0;
    tmp_queue->head = NULL;
    tmp_queue->tail = NULL;

    return tmp_queue;
}

// Adds an item at the tail of a Queue 
void enqueue(Queue self, int32_t item) {
    Node tmp_node = malloc(sizeof(struct Node));
    assert(tmp_node != NULL && "Could not allocate memory for Node to insert in Queue");

    tmp_node->value = item;
    tmp_node->next = NULL;

    if (self->tail == NULL) {
        self->head = tmp_node;
        self->tail = tmp_node;
    } else {
        self->tail->next = tmp_node;
        self->tail = tmp_node;
    }

    self->len += 1;
}

// Removes and frees a Node from the Queue head;
// Returns the value from the head node or returns NULL if head doesn't exist
int32_t deque(Queue self) {
    if (self->head == NULL) {
        return (int32_t)NULL;
    }

    int32_t val = self->head->value;

    Node tmp_head = self->head;
    self->head = self->head->next;
    self->len -= 1;

    free(tmp_head);
    tmp_head = NULL;

    return val;
}

// Returns the value of head Node;
// Returns NULL if head doesn't exist
int32_t peek(Queue self) {
    if (self->head == NULL)
        return (int32_t)NULL;

    return self->head->value;
}

// Frees the whole Queue in memory
void freeQueue(Queue self) {
    while (self->head != NULL) {
        Node tmp_head = self->head;
        self->head = self->head->next;

        free(tmp_head);
        tmp_head = NULL;
    }

    free(self);
    self = NULL;
}

// Get the lenght of the Queue
uint32_t getQueueLen(Queue self) {
    return self->len;
}
