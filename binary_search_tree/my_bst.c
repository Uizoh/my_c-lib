#include "my_bst.h"

typedef struct BNode {
    int32_t key;
    uint32_t occurrence_count;
    struct BNode* left;
    struct BNode* right;
} BNode;


typedef struct BST {
    BNode* root;
} BST;

BST* bstNew() {
    BST* temp = malloc(sizeof(BST));
    assert(temp != NULL && "Failed to allocate memory for Binary Tree Struct");
    temp->root = NULL;

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

void bstInsert(BST* self, int32_t key) {
    insertNode(&self->root, key);
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

        } else {
        free(*root);
        *root = NULL;
        return true;
        }

    } else {
        return false;
    }
}

bool bstDelete(BST* self, int32_t key) {
    return deleteNode(&self->root, key);
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

bool bstSearch(BST* self, int32_t key) {
    return searchNode(self->root, key);
}

void printNode(BNode* root) {
    if (root == NULL) {
        return;
    } else {
        printNode(root->left);
        printf("%d ", root->key);
        printNode(root->right);
    }
}

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
        root = NULL;
    }
}

void bstFree(BST* self) {
    freeNode(self->root);
    free(self);
}

