#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct String {
    u32 len;
    u32 cap;
    char* __str;
}* String;

// Creates a new String struct with a initial size parameter or default values;
// Default values: capacity = 10, lenght = 1
String string_new(u32 init_size) {
    if (init_size == NULL)
        init_size = 10;
    String temp = malloc(sizeof(struct String));
    temp->__str = malloc(init_size);
    temp->len = 1;
    temp->cap = init_size;

    return temp;
}

// Set a string value to a new or existing String struct;
// Automatically resizes if the new string size is bigger than the current
// capacity
void string_set(String self, char* new_string) {
    if (strlens(new_string) >= self->len) {
        self->__str = realloc(self->__str, strlens(new_string));
        self->cap = strlens(new_string);
    }

    memset(self->__str, '\0', self->cap);

    self->len = strlens(new_string) - 1;
    strncpy(self->__str, new_string, strlens(new_string));
}

// Creates a new String struct with an existing string as a parameter
String string_from(char* string_value) {
    String temp = string_new(strlens(string_value));
    string_set(temp, string_value);

    return temp;
}

// Simply get the string from the String struct
char* string_get(String self) {
    return self->__str;
}

// Reallocates the String struct's capacity according with it's current lenght;
// Does nothing if it's already good to go
void string_resize(String self) {
    if ((self->len + 1) != self->cap) {
        // (self-> + 1) is needed because capacity also includes the NULL
        // terminator, which (self->len) doesn't
        self->__str = realloc(self->__str, self->len + 1);
        self->cap = self->len + 1;
    }
}

// Free all the allocated memory from the String struct
void string_free(String self) {
    free(self->__str);
    self->__str = NULL;
    free(self);
    self = NULL;
}

int main() {
    String name = string_from("Saba");

    printf("%s\n", string_get(name));

    printf("%s\n%d, %d\n", string_get(name), name->len, name->cap);

    string_set(name,
               "ssssssssssssssssssssssssssssssssssssssssssssssssssssssssd");

    printf("%s\n%d, %d\n", string_get(name), name->len, name->cap);
    string_set(name, "abc");
    string_resize(name);
    printf("%s\n%d, %d\n", string_get(name), name->len, name->cap);
    printf("%ld\n", strlens("abc"));
    return 0;
}
