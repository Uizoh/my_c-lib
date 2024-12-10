#include "my_defaults.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum TypeVec { INT, UINT, FLOAT } TypeVec;

typedef struct Vec {
    u32 len;
    u32 capacity;
    TypeVec type;
    union {
        i32* _arr_i;
        u32* _arr_u;
        f32* _arr_f;
    }
}* Vec;

void null_check(void* ptr, str err_msg) {
    if (ptr == NULL) {
        printf("%s\n", err_msg);
        exit(EXIT_FAILURE);
    }
}

Vec vec_new(TypeVec type, u32 init_cap) {
    Vec temp = malloc(sizeof(struct Vec));
    null_check(temp, "Failed to allocate the vector");
    temp->type = type;

    switch (temp->type) {
    case INT:
        temp->_arr_i = malloc(sizeof(i32) * init_cap);
        null_check(temp->_arr_i, "Failed to allocate memory for vector");
        break;
    case UINT:
        temp->_arr_u = malloc(sizeof(u32) * init_cap);
        null_check(temp->_arr_u, "Failed to allocate memory for vector");
        break;
    case FLOAT:
        temp->_arr_f = malloc(sizeof(f32) * init_cap);
        null_check(temp->_arr_f, "Failed to allocate memory for vector");
        break;
    }

    temp->len = 0;
    temp->capacity = init_cap;

    return temp;
}

void vec_append(Vec self, void* item) {
    if (self->len >= self->capacity) {
        self->capacity += 50;

        switch (self->type) {
        case INT:
            self->_arr_i = realloc(self->_arr_i, sizeof(i32) * self->capacity);
            break;
        case UINT:
            self->_arr_u = realloc(self->_arr_u, sizeof(u32) * self->capacity);
            break;
        case FLOAT:
            self->_arr_f = realloc(self->_arr_f, sizeof(f32) * self->capacity);
            break;
        }
    }

    switch (self->type) {
    case INT:
        self->_arr_i[self->len] = *(i32*)item;
        break;
    case UINT:
        self->_arr_u[self->len] = *(u32*)item;
        break;
    case FLOAT:
        self->_arr_f[self->len] = *(f32*)item;
        break;
    }
    self->len += 1;
}

void vec_free(Vec self) {
    switch (self->type) {
    case INT:
        free(self->_arr_i);
        self->_arr_i = NULL;
        break;
    case UINT:
        free(self->_arr_u);
        self->_arr_u = NULL;
        break;
    case FLOAT:
        free(self->_arr_f);
        self->_arr_f = NULL;
        break;
    }
    free(self);
    self = NULL;
}

int main() {
    printf("Hello world\n");
    Vec some = vec_new(FLOAT, 10);
    f32 a = 45.45;
    vec_append(some, &a);
    printf("%f\n", some->_arr_f[0]);

    return 0;
}
