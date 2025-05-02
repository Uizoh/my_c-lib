#ifndef ARENA_POOL_
#define ARENA_POOL_

#include "my_defaults.h"


// Arena Pool struct pointer
typedef struct ArenaPool* ArenaPool;

// Allocates new Arena Pool and given capacity and returns it
ArenaPool arenaNew(uint32_t capacity);

// Adds given element to an Arena Pool
void arenaAdd(ArenaPool self, void* item);

// Deallocates the last element in the Arena Pool
void arenaFreeLast(ArenaPool self);

// Deallocates all the elements added in a Arena Pool
void arenaFreeAll(ArenaPool self);

// Deallocates the whole Arena Pool struct along with it's elements
void arenaFree(ArenaPool self);

// Get the lenght of Arena Pool
uint32_t arenaGetLen(ArenaPool self);

// Get the capacity of Arena Pool
uint32_t arenaGetCap(ArenaPool self);


#endif
