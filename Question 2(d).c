#include <stdio.h>
#include <stdlib.h>

// Defining the order of the B-tree
#define t 3

// Defining the B-tree node structure
struct BTreeNode {
    int n; // The number of keys in the node
    int keys[2 * t - 1]; // This is the array to store keys
    struct BTreeNode *children[2 * t]; // This is the array to store pointers to children
};

// This is the function to create a new B-tree node
struct BTreeNode *createNode() {
    struct BTreeNode *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    if (newNode == NULL) {
        perror("Error creating a new node");
        exit(EXIT_FAILURE);
    }

    newNode->n = 0;

    // Initializing all pointers to NULL
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

    // Setting the number of keys in the node
    node->n = 4; // Since we are populating four keys

    // Initializing all pointers to NULL
    for (int i = 0; i < 2 * t; i++) {
        node->children[i] = NULL;
    }
}

// This is the function to print the key values and addresses described by the pointers in a B-tree node
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

// This is the function to insert a value into a B-tree node if there is space
void insertVal2Node(struct BTreeNode *node, int val) {
    int i = node->n - 1;

    // To find the position for the new value
    while (i >= 0 && val < node->keys[i]) {
        node->keys[i + 1] = node->keys[i];
        i--;
    }

    // Inserting the new value
    node->keys[i + 1] = val;
    node->n++;

    // Sorting the keys in the node
    i = 0;
    while (i < node->n - 1 && node->keys[i] > node->keys[i + 1]) {
        // Swap keys
        int temp = node->keys[i];
        node->keys[i] = node->keys[i + 1];
        node->keys[i + 1] = temp;
        i++;
    }
}

int main() {
    // Creating a B-tree node
    struct BTreeNode *root = createNode();

    // Populating the node with keys 70, 20, 30, 48
    populateNode(root, 70, 20, 30, 48);

    // Printing the keys before insertion
    printf("Keys before insertion: ");
    printNode(root);

    // Insert the value 52 into the node
    insertVal2Node(root, 52);

    // Printing the keys after insertion
    printf("Keys after insertion: ");
    printNode(root);

    free(root);

    return 0;
}

