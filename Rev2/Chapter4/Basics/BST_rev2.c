/*
 * Implement basic tree primitives
 * InsertNode
 * Inorder
 * PreOrder
 * PostOrder
 * DeleteNode
 */
#include <stdio.h>
#include <stdlib.h>

/* Each tree node */
struct node {
    int data;
    struct node* left;
    struct node* right;

};

struct node* createNode(int item) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* InsertNode(struct node* root, int item) {
    if(root == NULL) return(createNode(item));
    else {
        if(root->data >= item)
            root->left = InsertNode(root->left, item);
        else
            root->right = InsertNode(root->right, item);
        }
    return root;
}

void Inorder(struct node* root) {
    if(root == NULL) return;
    else {
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;

    root = InsertNode(root, 6);
    root = InsertNode(root, 4);
    root = InsertNode(root, 8);
    root = InsertNode(root, 2);
    root = InsertNode(root, 9);

    Inorder(root);

    return 0;
}
