#include <stdio.h>
#include <stdlib.h>

// Defining the order of the B-tree
#define t 3

// Defining the B-tree node structure
struct BTreeNode {
    int n; // The number of keys in the node
    int keys[2 * t - 1]; // This is the array to store keys
    struct BTreeNode *children[2 * t]; // This is an array to store pointers to children
};

// The function to allocate memory for a B-tree node
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

// The function to print the key values and addresses described by the pointers in a B-tree node
void printNode(struct BTreeNode *node) {
    printf("Keys in the node: ");
    for (int i = 0; i < node->n; i++) {
        printf("%d ", node->keys[i]);
    }
    printf("\n");

    printf("Addresses of children: ");
    for (int i = 0; i <= node->n; i++) {
        printf("%p ", (void *)node->children[i]);
    }
    printf("\n");
}

int main() {
    // Allocating memory for a B-tree node
    struct BTreeNode *newNode = getNode();

    // Populating the node with keys 70, 20, 30, 48
    newNode->keys[0] = 70;
    newNode->keys[1] = 20;
    newNode->keys[2] = 30;
    newNode->keys[3] = 48;
    newNode->n = 4;

    // Printing the key values and addresses described by the pointers
    printNode(newNode);

 
    free(newNode);

    return 0;
}

