#include "mylib.h"
#include <stdlib.h>

typedef struct Vec {
    u32 len;
    u32 capacity;
    i32* arr;
}* Vec;

Vec vec_new(u32 init_cap) {
    Vec temp = malloc(sizeof(struct Vec));
    temp->arr = malloc(sizeof(i32) * init_cap);

    temp->len = 0;
    temp->capacity = init_cap;

    return temp;
}

void vec_append(Vec self, i32 item) {
    if (self->len >= self->capacity) {
        self->capacity += 50;
        self->arr = realloc(self->arr, sizeof(i32) * self->capacity);
    }

    self->arr[self->len] = (i32)item;
    self->len += 1;
}

void vec_free(Vec self) {
    free(self->arr);
    self->arr = NULL;
    free(self);
    self = NULL;
}
