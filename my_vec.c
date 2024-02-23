#include "my_defaults.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum TypeVec { INT, UINT, FLOAT } TypeVec;

typedef struct Vec {
    u32 len;
    u32 capacity;
    TypeVec type;
    i32* _arr_i;
    u32* _arr_u;
    f32* _arr_f;
}* Vec;

Vec vec_new(TypeVec type, u32 init_cap) {
    Vec temp = malloc(sizeof(struct Vec));
    temp->type = type;

    switch (type) {
    case INT:
        temp->_arr_i = malloc(sizeof(i32) * init_cap);
    case UINT:
        temp->_arr_u = malloc(sizeof(u32) * init_cap);
    case FLOAT:
        temp->_arr_f = malloc(sizeof(f32) * init_cap);
    }

    temp->len = 0;
    temp->capacity = init_cap;

    return temp;
}

void vec_append(Vec self, i32 item) {
    if (self->len >= self->capacity) {
        self->capacity += 50;

        switch (self->type) {
        case INT:
            self->_arr_i = realloc(self->_arr_i, sizeof(i32) * self->capacity);
        case UINT:
            self->_arr_u = realloc(self->_arr_u, sizeof(u32) * self->capacity);
        case FLOAT:
            self->_arr_f = realloc(self->_arr_f, sizeof(f32) * self->capacity);
        }
    }

    switch (self->type) {
    case INT:
        self->_arr_i[self->len] = item;
    case UINT:
        self->_arr_u[self->len] = item;
    case FLOAT:
        self->_arr_f[self->len] = item;
    }
    self->len += 1;
}

void vec_free(Vec self) {
    switch (self->type) {
    case INT:
        free(self->_arr_i);
        self->_arr_i = NULL;
    case UINT:
        free(self->_arr_u);
        self->_arr_u = NULL;
    case FLOAT:
        free(self->_arr_f);
        self->_arr_f = NULL;
    }
    free(self);
    self = NULL;
}

int main() {
    printf("Hello world\n");
    Vec some = vec_new(UINT, 10);
    vec_append(some, 45);
    printf("%d\n", some->type);

    return 0;
}
