/*
 * Check if a tree is BST
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Define the node structure */
struct node {
  int data; //Data on the tree node
  struct node* left; //left child
  struct node* right; //Right child
};

/* Create a new Node */
struct node* createNode(int item) {
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  if(newNode == NULL) {
    printf("Couldn't allocate memory\n");
    return NULL;
  }
  newNode->data = item;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode; //return the newNode
}


/* Insert a newNode */
struct node* Insert(struct node* root, int item) {
  /* If it is the first node make it the root */
  if(root == NULL) return(createNode(item));
  else {
    /* Figure out a poisiton to insert */
    if(root->data >= item)
      root->left = Insert(root->left, item);
    else
      root->right = Insert(root->right, item);

    return root; //Return the root to the tree
  }
}


/* Inorder traversal of the tree */
bool isBST(struct node* root) {
  static struct node* prev = NULL;
  /* If the tree is empty just return */
  if(root == NULL) return true;
  else {
    isBST(root->left);
    if(prev!=NULL && root->data <= prev->data)
      return false;
    prev = root;
    isBST(root->right);
  }
  return true;
}


int main() {
  struct node* root = NULL;

  root = Insert(root, 4);
  root = Insert(root, 2);
  root = Insert(root, 6);

  if(isBST(root))
    printf("It is a BST\n");
  

  return 0;
}
