
#include <stdio.h>
#include <stdlib.h>

// This code satisfies our definition for a binary tree node:
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// This code structures to fully represent a stack node:
struct StackNode {
    struct TreeNode *node;
    struct StackNode *next;
};

// This code structures to also represent a stack:
struct Stack {
    struct StackNode *top;
};

// The code to initialize a stack:
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// This code enables us to push a node onto the stack:
void push(struct Stack* stack, struct TreeNode* node) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->node = node;
    stackNode->next = stack->top;
    stack->top = stackNode;
}

// This code enables us to pop a node from the stack:
struct TreeNode* pop(struct Stack* stack) {
    if (stack->top == NULL)
        return NULL;
    struct StackNode* stackNode = stack->top;
    struct TreeNode* node = stackNode->node;
    stack->top = stack->top->next;
    free(stackNode);
    return node;
}

// This code ensures that we have used the inorder traversal without recursion whilst using a stack:
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 1000); // Assuming a maximum of 1000 nodes
    *returnSize = 0;

    struct Stack* stack = createStack();
    struct TreeNode* current = root;

    while (current != NULL || stack->top != NULL) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }
        current = pop(stack);
        result[(*returnSize)++] = current->val;
        current = current->right;
    }

    return result;
}

int main() {
    // This code creates a sample binary tree:
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = NULL;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 2;
    root->right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->left->val = 3;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = NULL;

    int returnSize;
    int* result = inorderTraversal(root, &returnSize);

    // Printing the final result:
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    free(result);
    free(root->right->left);
    free(root->right);
    free(root);
    
    return 0;
}