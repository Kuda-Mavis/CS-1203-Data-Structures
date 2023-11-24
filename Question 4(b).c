#include <stdio.h>
#include <stdlib.h>

// Structure for a search tree node
typedef struct TreeNode {
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// The function to create a new tree node
TreeNode *createNode(int key) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// The function to insert a key into the tree
TreeNode *insert(TreeNode *root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

// The function to search for a key in the tree
TreeNode *search(TreeNode *root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// The function to print the tree in inorder traversal
void inorderTraversal(TreeNode *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Driver program
int main() {
    TreeNode *root = NULL;

    // Insert keys into the tree
    int keys[] = {70, 20, 30, 48, 52, 64, 11, 98, 77, 82, 89, 15};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < numKeys; i++) {
        root = insert(root, keys[i]);
    }

    // Printing the tree in inorder traversal
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}

