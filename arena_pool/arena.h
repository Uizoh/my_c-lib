#ifndef ARENA_POOL_
#define ARENA_POOL_

#include "my_defaults.h"


// Arena Pool struct pointer
typedef struct ArenaPool* ArenaPool;

// Allocates new Arena Pool and given capacity and returns it
ArenaPool arenaNew(uint32_t capacity);
// Adds given element to an Arena Pool
void arenaAdd(ArenaPool self, void* item);
// Deallocates the elements added in a Arena Pool
void arenaFreeElements(ArenaPool self);
// Deallocates the whole Arena Pool
void arenaFreeEverything(ArenaPool self);
// Get the lenght of Arena Pool
uint32_t arenaGetLen(ArenaPool self);
// Get the capacity of Arena Pool
uint32_t arenaGetCap(ArenaPool self);


#endif
