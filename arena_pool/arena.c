#include "arena.h"
#include <stdlib.h>

// Arena Pool struct pointer
typedef struct ArenaPool {
    uint32_t len;
    uint32_t cap;
    void** arr;
}* ArenaPool;

// Allocates new Arena Pool and given capacity and returns it
ArenaPool arenaNew(uint32_t capacity) {
    ArenaPool tmp = malloc(sizeof(struct ArenaPool));
    assert(tmp != NULL && "Failed to allocate memory for Arena Pool");

    tmp->arr = malloc(sizeof(void *) * capacity);
    assert(tmp->arr != NULL && "Failed to allocate memory for Arena Pool");

    tmp->len = 0;
    tmp->cap = capacity;

    return tmp;
}

// Adds given element to an Arena Pool
void arenaAdd(ArenaPool self, void* item) {
    assert(self->len <= self->cap && "Arena Pool capacity was exceded");

    self->arr[self->len] = item;
    self->len += 1;
}

// Deallocates the elements added in a Arena Pool
void arenaFreeElements(ArenaPool self) {
    for (uint32_t i = 0; i < self->len; i++) {
        free(self->arr[i]);
        self->arr[i] = NULL;
    }

    self->len = 0;
}

// Deallocates the whole Arena Pool
void arenaFreeEverything(ArenaPool self) {
    arenaFreeElements(self);
    free(self->arr);
    free(self);
    self = NULL;
}

// Get the lenght of Arena Pool
uint32_t arenaGetLen(ArenaPool self) {
    return self->len;
}

// Get the capacity of Arena Pool
uint32_t arenaGetCap(ArenaPool self) {
    return self->cap;
}

