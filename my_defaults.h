<<<<<<< HEAD
#ifndef MY_DEFAULTS_
#define MY_DEFAULTS_

#include <stdbool.h>
#include <stdint.h>

#define len(arr) sizeof(arr) / sizeof(*arr)
#define rand_between(min, max) rand() % (max - min + 1) + min
#define dump(var) #var

typedef float float32_t;
typedef double float64_t;
typedef long double float128_t;
=======
#ifndef MY_LIB_
#define MY_LIB_

#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define len(arr) sizeof(arr) / sizeof(*arr)
#define strlens(x) (strlen(x) + 1)
#define rand_between(min, max) rand() % (max - min + 1) + min
#define assert_eq(x, y) assert(x == y)
#define dump(var) #var

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef float f32;
typedef double f64;
>>>>>>> 1113ed3a548130dd94b8246cadb88dcf16a9c042
typedef const char* str;

#endif
