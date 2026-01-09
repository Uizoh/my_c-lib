#ifndef MY_STRING_
#define MY_STRING_

#include "my_defaults.h"
#include <string.h>


// String struct pointer
typedef struct String String;

// All the relative functions
String* newString(uint32_t init_size);
void setString(String* self, char* new_string);
String* stringFrom(char* string_value);
char* getString(String* self);
void resizeString(String* self);
void freeString(String* self);
uint32_t getStringLen(String* self);
uint32_t getStringCap(String* self);


#endif
