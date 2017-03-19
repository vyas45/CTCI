/*
 * Defining the binary Search Tree primitives
 */
#include <stdio.h>
#include <stdlib.h>

/* Define the structure for a tree node */
struct node {
  int data;
  struct node* left;
  struct node* right;
};

/* Create a new Node */
struct node* createNode(int item) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = item;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

/* Insert a new Node into the tree */
struct node* Insert(struct node* root, int data) {
  if(root==NULL) {
    return (createNode(data));
  }
    if(root->data >= data)
        root->left = Insert(root->left, data);
    else
        root->right =Insert(root->right, data);
  /* Return the updated tree */
  return root;
}

/* Traverse the nodes inOrder */
void Inorder(struct node* root) {
  if(root == NULL) return;
  else {
    Inorder(root->left);
    printf("%d-> ", root->data);
    Inorder(root->right);
  }
}

int main() {
  struct node* root = NULL;

  root = Insert(root, 2);
  root = Insert(root, 1);
  root = Insert(root, 3);
  root = Insert(root, 4);
  root = Insert(root, 0);
  root = Insert(root, 6);

  printf("The root is %d\n", root->data);

  /* Print inOrder */
  Inorder(root);

  return 0;
}
