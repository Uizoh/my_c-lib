#include "my_defaults.h"
#include "my_string.h"
#include <stdlib.h>

#define strlens(x) (strlen(x) + 1) // For '\0' character

// String struct pointer
typedef struct String {
    uint32_t len;
    uint32_t cap;
    char* __str;
}* String;

// Creates a new String struct with a initial size parameter
String newString(uint32_t init_size) {
    String temp = malloc(sizeof(struct String));
    temp->__str = malloc(init_size);
    temp->len = 0;
    temp->cap = init_size;

    return temp;
}

// Set a string value to a new or existing String struct;
// Automatically resizes if the new string size is bigger than the current
// capacity
void setString(String self, char* new_string) {
    if (strlens(new_string) >= self->len) {
        self->__str = realloc(self->__str, strlens(new_string));
        self->cap = strlens(new_string);
    }

    memset(self->__str, '\0', self->cap);

    self->len = strlens(new_string) - 1;
    strncpy(self->__str, new_string, strlens(new_string));
}

// Creates a new String struct with an existing string as a parameter
String stringFrom(char* string_value) {
    String temp = newString(strlens(string_value));
    setString(temp, string_value);

    return temp;
}

// Simply get the string from the String struct
char* getString(String self) {
    return self->__str;
}

// Reallocates the String struct's capacity according with it's current lenght;
// Does nothing if it's already good to go
void resizeString(String self) {
    if ((self->len + 1) != self->cap) {
        // (self-> + 1) is needed because capacity also includes the NULL
        // terminator, which (self->len) doesn't
        self->__str = realloc(self->__str, self->len + 1);
        self->cap = self->len + 1;
    }
}

// Free all the allocated memory from the String struct
void freeString(String self) {
    free(self->__str);
    self->__str = NULL;
    free(self);
    self = NULL;
}

// Returns the lenght of the string
uint32_t getStringLen(String self) {
    return self->len;
}

// Returns the capacity of the string
uint32_t getStringCap(String self) {
    return self->cap;
}

