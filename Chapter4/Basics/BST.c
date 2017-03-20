/*
 * Defining the binary Search Tree primitives
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

/* Search for a node in the tree */
bool isNode(struct node* root, int data) {
  if(root == NULL) return false;

  /* Found the node */
  if(root->data == data){
    return true;
  }
  /* Otherwise treaverse sub-trees */
  else {
    return(isNode(root->left, data) || isNode(root->right, data));
  }
  return false;
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
  printf("\n");

  /* Is the node in the tree */
  if(isNode(root, 4))
    printf("Found 4 in the tree\n");
  else
    printf("Did not find 4 in the tree\n");
  if(isNode(root, 7))
    printf("Found 7 in the tree\n");
  else
    printf("Did not find 7 in the tree\n");


  return 0;
}
