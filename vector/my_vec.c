#include "my_defaults.h"
#include "my_vec.h"
#include <stdlib.h>


// For using in Vector struct creation with appropriate types
typedef enum VecType { INT, UINT, FLOAT } VecType;

// Vector struct pointer
typedef struct Vec {
    uint32_t len;
    uint32_t capacity;
    VecType type;
    union {
        int32_t* _arr_i;
        uint32_t* _arr_u;
        float64_t* _arr_f;
    };
} Vec;

void nullcheck(void* ptr){
    assert(ptr != NULL && "Failed to allocate memory for vector");
}

// Creates a new Vec struct with a Vector type and initial capacity
Vec* newVec(VecType type, uint32_t init_cap) {
    Vec* temp = malloc(sizeof(struct Vec));
    nullcheck(temp);
    temp->type = type;

    // Allocate memory for given type 
    switch (temp->type) {
    case INT:
        temp->_arr_i = malloc(sizeof(int32_t) * init_cap);
        nullcheck(temp->_arr_i);
        break;
    case UINT:
        temp->_arr_u = malloc(sizeof(uint32_t) * init_cap);
        nullcheck(temp->_arr_u);
        break;
    case FLOAT:
        temp->_arr_f = malloc(sizeof(float64_t) * init_cap);
        nullcheck(temp->_arr_f);
        break;
    }

    temp->len = 0;
    temp->capacity = init_cap;

    return temp;
}

// Appends a new element for an exitsting Vector;
// Reallocates more memory if items exceed the Vector capacity
void appendVec(Vec* self, void* item) {
    if (self->len >= self->capacity) {
        self->capacity += 50;   // Default lenght growth value

        switch (self->type) {
        case INT:
            self->_arr_i = realloc(self->_arr_i, sizeof(int32_t) * self->capacity);
            break;
        case UINT:
            self->_arr_u = realloc(self->_arr_u, sizeof(uint32_t) * self->capacity);
            break;
        case FLOAT:
            self->_arr_f = realloc(self->_arr_f, sizeof(float64_t) * self->capacity);
            break;
        }
    }

    switch (self->type) {
    case INT:
        self->_arr_i[self->len] = *(int32_t*)item;
        break;
    case UINT:
        self->_arr_u[self->len] = *(uint32_t*)item;
        break;
    case FLOAT:
        self->_arr_f[self->len] = *(float64_t*)item;
        break;
    }
    self->len += 1;
}

// Removes the item from the given index;
// Passing -1 as index removes the last element from the vector
void popVec(Vec* self, uint32_t index) {
    assert(index < -1 || index >= self->len && "Given index exceeds vector lenght");

    if (index == -1) {
        switch (self->type) {
            case INT:
                self->_arr_i[self->len - 1] = '\0';
            case UINT:
                self->_arr_u[self->len - 1] = '\0';
            case FLOAT:
                self->_arr_f[self->len - 1] = '\0';
        }

    }

    switch (self->type) {
        case INT:
            self->_arr_i[index] = '\0';
        case UINT:
            self->_arr_u[index] = '\0';
        case FLOAT:
            self->_arr_f[index] = '\0';
    }
}

// Get a slice of a Vector array with index bounds;
// Returns a heap allocated array with elements within the given index
void* sliceVec(Vec* self, uint32_t starting_index, uint32_t last_index) {
    if (self->_arr_i != NULL) {
        int32_t* arr = malloc(self->len * sizeof(int32_t));

        for (int32_t i = starting_index; i <= last_index; i++) {
            arr[i] = self->_arr_i[i];
        }

        return arr;
    }

    if (self->_arr_u != NULL) {
        uint32_t* arr = malloc(self->len * sizeof(uint32_t));

        for (int32_t i = starting_index; i <= last_index; i++) {
            arr[i] = self->_arr_u[i];
        }

        return arr;
    }

    if (self->_arr_f != NULL) {
        float64_t* arr = malloc(self->len * sizeof(float64_t));

        for (int32_t i = starting_index; i <= last_index; i++) {
            arr[i] = self->_arr_f[i];
        }

        return arr;
    }
}

// Deallocates the Vector 
void freeVec(Vec* self) {
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

// Get Vector lenght
uint32_t getVecLen(Vec* self) {
    return self->len;
}

// Get Vector capacity
uint32_t getVecCap(Vec* self) {
    return self->capacity;
}

// Get Vector type
VecType getVecType(Vec* self) {
    return self->type;
}

