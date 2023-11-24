#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int key) {
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode *insert(struct TreeNode *root, int key) {
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

void printTree(struct TreeNode *root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%d ", root->key);
        printTree(root->right);
    }
}

struct TreeNode *search(struct TreeNode *root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

int main() {
    struct TreeNode *root = NULL;
    int insertKeys[] = {70, 20, 30, 48, 52, 64, 11, 98, 77, 82, 89, 15};
    int numInsertKeys = sizeof(insertKeys) / sizeof(insertKeys[0]);

    for (int i = 0; i < numInsertKeys; i++) {
        root = insert(root, insertKeys[i]);
    }

    printf("Binary Search Tree: ");
    printTree(root);
    printf("\n");

    // Demonstrate search
    int searchKey1 = 48;
    struct TreeNode *result1 = search(root, searchKey1);

    if (result1 != NULL) {
        printf("Key %d found in the tree.\n", searchKey1);
    } else {
        printf("Key %d not found in the tree.\n", searchKey1);
    }

    int searchKey2 = 99;
    struct TreeNode *result2 = search(root, searchKey2);

    if (result2 != NULL) {
        printf("Key %d found in the tree.\n", searchKey2);
    } else {
        printf("Key %d not found in the tree.\n", searchKey2);
    }

    return 0;
}

