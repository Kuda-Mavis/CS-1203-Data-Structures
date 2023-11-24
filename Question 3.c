#include <stdio.h>
#include <stdlib.h>

#define t 2

struct TreeNode {
    int n; // Number of keys
    int keys[2 * t - 1];
    struct TreeNode *children[2 * t];
};

struct TreeNode *createNode() {
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->n = 0;
    for (int i = 0; i < 2 * t - 1; i++) {
        newNode->keys[i] = 0;
        newNode->children[i] = NULL;
    }
    newNode->children[2 * t - 1] = NULL;
    return newNode;
}

void splitChild(struct TreeNode *x, int i) {
    struct TreeNode *y = x->children[i];
    struct TreeNode *z = createNode();
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++) {
        z->keys[j] = y->keys[j + t];
    }

    if (y->children[0] != NULL) {
        for (int j = 0; j < t; j++) {
            z->children[j] = y->children[j + t];
        }
    }

    y->n = t - 1;

    for (int j = x->n; j > i; j--) {
        x->children[j + 1] = x->children[j];
    }

    x->children[i + 1] = z;

    for (int j = x->n - 1; j >= i; j--) {
        x->keys[j + 1] = x->keys[j];
    }

    x->keys[i] = y->keys[t - 1];
    x->n++;
}

void insertVal2NodeBreak(struct TreeNode *x, int k) {
    int i = x->n - 1;

    if (x->children[0] != NULL) {
        while (i >= 0 && k < x->keys[i]) {
            i--;
        }

        i++;

        if (x->children[i]->n == 2 * t - 1) {
            splitChild(x, i);

            if (k > x->keys[i]) {
                i++;
            }
        }

        insertVal2NodeBreak(x->children[i], k);
    } else {
        int j = x->n - 1;

        while (j >= 0 && k < x->keys[j]) {
            x->keys[j + 1] = x->keys[j];
            j--;
        }

        x->keys[j + 1] = k;
        x->n++;
    }
}

void insert(struct TreeNode **root, int k) {
    struct TreeNode *r = *root;

    if (r->n == 2 * t - 1) {
        struct TreeNode *s = createNode();
        *root = s;
        s->children[0] = r;
        splitChild(s, 0);
        insertVal2NodeBreak(s, k);
    } else {
        insertVal2NodeBreak(r, k);
    }
}

void printTree(struct TreeNode *root) {
    if (root != NULL) {
        for (int i = 0; i < root->n; i++) {
            printTree(root->children[i]);
            printf("%d ", root->keys[i]);
        }
        printTree(root->children[root->n]);
    }
}

int main() {
    struct TreeNode *root = createNode();

    int insertKeys[] = {20, 30, 48, 52, 70, 64};
    int numInsertKeys = sizeof(insertKeys) / sizeof(insertKeys[0]);

    for (int i = 0; i < numInsertKeys; i++) {
        insert(&root, insertKeys[i]);
    }

    printf("B-Tree: ");
    printTree(root);

    return 0;
}


