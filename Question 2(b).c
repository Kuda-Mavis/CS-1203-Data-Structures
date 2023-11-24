#include <stdio.h>
#include <stdlib.h>

// Defining the order of the B-tree
#define t 3

// Defining the B-tree node structure
struct BTreeNode {
    int n; // This is the number of keys in the node
    int keys[2 * t - 1]; // This is the array to store keys
    struct BTreeNode *children[2 * t]; // This is the array to store pointers to children
};

// This is a function to allocate memory for a B-tree node
struct BTreeNode *getNode() {
    struct BTreeNode *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    if (newNode == NULL) {
        perror("Error allocating memory for a new node");
        exit(EXIT_FAILURE);
    }

    newNode->n = 0;

    // Initializing all pointers to NULL
    for (int i = 0; i < 2 * t; i++) {
        newNode->children[i] = NULL;
    }

    return newNode;
}

int main() {
    // Allocating memory for a B-tree node
    struct BTreeNode *newNode = getNode();

    // Displaying a message indicating successful allocation
    printf("Memory allocated for a new B-tree node.\n");

    
    free(newNode);

    return 0;
}


