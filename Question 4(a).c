#include <stdio.h>
#include <stdlib.h>

// Node structure for the search tree
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

// function to create a new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// function to insert a key into the search tree
struct Node* insert(struct Node* root, int key) {
    // If the tree is empty, create a new node as the root
    if (root == NULL) {
        return createNode(key);
    }

    // Traversing the tree to find the appropriate position for the key
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

// function to search for a key in the search tree
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at the root
    if (root == NULL || root->key == key) {
        return root;
    }

    // key is greater than root's key
    if (root->key < key) {
        return search(root->right, key);
    }

    // key is smaller than root's key
    return search(root->left, key);
}

// function to print the inorder traversal of the search tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Inserting keys into the search tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Printing the inorder traversal of the search tree
    printf("Inorder traversal of the tree: ");
    inorderTraversal(root);
    printf("\n");

    // Searching for a key in the search tree
    int key_to_search = 48;
    struct Node* result = search(root, key_to_search);
    if (result != NULL) {
        printf("Key %d is found in the tree.\n", key_to_search);
    } else {
        printf("Key %d is not found in the tree.\n", key_to_search);
    }

    
}
