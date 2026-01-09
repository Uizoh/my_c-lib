#ifndef MY_BST_IMPL_
#define MY_BST_IMPL_

#include "my_defaults.h"
#include <stdio.h>
#include <stdlib.h>

// Binary Search Tree sturct
typedef struct BST BST;

// Creates a new heap allocated BST and returns a pointer to it
BST* bstNew();

// Inserts a node to the BST with the given key
void bstInsert(BST* self, int32_t key);

// Delete a key from the BST; returns true if deleted or false if not found
bool bstDelete(BST* self, int32_t key);

// Searches for a key in the BST; returns true if found or false if not found
bool bstSearch(BST* self, int32_t key);

// Traverse and print all keys from the BST
void bstTraverse(BST* self);

// Free the all the BNodes and the BST from the heap memory
void bstFree(BST* self);

#endif
