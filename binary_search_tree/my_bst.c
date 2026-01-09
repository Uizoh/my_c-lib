#include "my_bst.h"


typedef struct BNode {
    int32_t key;
    uint32_t occurrence_count;
    struct BNode* left;
    struct BNode* right;
} BNode;


// Binary Search Tree sturct
typedef struct BST {
    BNode* root;
    uint32_t size;
} BST;


// Creates a new heap allocated BST and returns a pointer to it
BST* bstNew() {
    BST* temp = malloc(sizeof(BST));
    assert(temp != NULL && "Failed to allocate memory for Binary Tree Struct");
    temp->root = NULL;
    temp->size = 0;

    return temp;
}


void insertNode(BNode** root, int32_t key) {
    if (*root == NULL) {
        BNode* temp = malloc(sizeof(BNode));

        assert(temp != NULL && "Failed to allocate memory for Binary Tree Node");

        temp->key = key;
        temp->occurrence_count = 1;
        temp->left = NULL;
        temp->right = NULL;

        *root = temp;
        return;

    } else if ((*root)->key == key) {
        (*root)->occurrence_count += 1;
        return;

    } else if (key < (*root)->key) {
        insertNode(&(*root)->left, key);
        return;

    } else if (key > (*root)->key) {
        insertNode(&(*root)->right, key);
        return;
    }
}

// Inserts a node to the BST with the given key
void bstInsert(BST* self, int32_t key) {
    insertNode(&self->root, key);
    self->size += 1;
}


bool deleteNode(BNode** root, int32_t key) {
    if (*root == NULL) {
        return false;

    } else if (key < (*root)->key) {
        return deleteNode(&(*root)->left, key);

    } else if (key > (*root)->key) {
        return deleteNode(&(*root)->right, key);

    } else if ((*root)->key == key) {

        if ((*root)->occurrence_count > 1) {
            (*root)->occurrence_count -= 1;
            return true;
        }

        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
            return true;
        }

        if ((*root)->left == NULL) {
            BNode* temp = *root;
            *root = (*root)->right;

            free(temp);

            return true;
        }

        if ((*root)->right == NULL) {
            BNode* temp = *root;
            *root = (*root)->left;

            free(temp);

            return true;
        }

        // Finding in-order successor and replacing with it
        BNode* succ = (*root)->right;

        while (succ->left != NULL) {
            succ = succ->left;
        }

        (*root)->key = succ->key;
        return deleteNode(&(*root)->right, succ->key);

    } else {
        return false;
    }
}

// Delete a key from the BST;
// Returns true if deleted or false if not found
bool bstDelete(BST* self, int32_t key) {
    bool res = deleteNode(&self->root, key);

    if (res) {
        self->size -= 1;
    }

    return res;
}


bool searchNode(BNode* root, int32_t key) {
    if (root == NULL) {
        return false;

    } else if (root->key > key) {
        return searchNode(root->left, key);

    } else if (root->key < key) {
        return searchNode(root->right, key);

    } else if (root->key == key) {
        return true;

    } else {
        return false;
    }
}

// Searches for a key in the BST; returns true if found or false if not found
bool bstSearch(BST* self, int32_t key) {
    return searchNode(self->root, key);
}


void printNode(BNode* root) {
    if (root == NULL) {
        return;
    } else {
        printNode(root->left);
        for (int i = 0; i < root->occurrence_count; i++) {
            printf("%d ", root->key);
        }
        printNode(root->right);
    }
}

// Traverse and print all keys from the BST
void bstTraverse(BST* self) {
    printNode(self->root);
}


void freeNode(BNode* root) {
    if (root == NULL) {
        return;
    } else {
        freeNode(root->left);
        freeNode(root->right);
        free(root);
    }
}

// Free the all the BNodes and the BST from the heap memory
void bstFree(BST* self) {
    freeNode(self->root);
    free(self);
}

// Get size of the BST
uint32_t bstGetSize(BST* self) {
    return self->size;
}

