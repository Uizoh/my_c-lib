#ifndef MY_STRING_
#define MY_STRING_


#include <string.h>
#define strlens(x) (strlen(x) + 1) // For '\0' character

// String struct pointer
typedef struct String {
    uint32_t len;
    uint32_t cap;
    char* __str;
} *String;

// All the relative functions
String newString(uint32_t init_size);
void setString(String self, char* new_string);
String stringFrom(char* string_value);
char* getString(String self);
void resizeString(String self);
void freeString(String self);


#endif
