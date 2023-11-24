#include <stdio.h>
#include <stdlib.h>

// This code defines the order of the B-tree
#define t 3

//This code defines the B-tree node structure
struct BTreeNode {
    int n; // This is the number of keys in the node
    int keys[2 * t - 1]; // This is the code for the array to store keys
    struct BTreeNode *children[2 * t]; // This is the code for the array to store pointers to children
};

// This is the function to create a new B-tree node
struct BTreeNode *createNode() {
    struct BTreeNode *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    if (newNode == NULL) {
        perror("Error creating a new node");
        exit(EXIT_FAILURE);
    }

    newNode->n = 0;

    // This code here initializes all pointers to NULL
    for (int i = 0; i < 2 * t; i++) {
        newNode->children[i] = NULL;
    }

    return newNode;
}

// This is the function to populate a B-tree node with given keys
void populateNode(struct BTreeNode *node, int key1, int key2, int key3, int key4) {
    node->keys[0] = key1;
    node->keys[1] = key2;
    node->keys[2] = key3;
    node->keys[3] = key4;

    // The code to set the number of keys in the node
    node->n = 4; // Since we are populating four keys

    // Again, initializeing all pointers to NULL
    for (int i = 0; i < 2 * t; i++) {
        node->children[i] = NULL;
    }
}

int main() {
    // Creating a B-tree node
    struct BTreeNode *root = createNode();

    // Populating the node with keys 70, 20, 30, 48
    populateNode(root, 70, 20, 30, 48);

    // Displaying the keys in the node
    printf("Keys in the node: ");
    for (int i = 0; i < root->n; i++) {
        printf("%d ", root->keys[i]);
    }
    printf("\n");

    free(root);

    return 0;
}

