/* Height of binary tree */
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
void Inorder(struct node* root) {
  /* If the tree is empty just return */
  if(root == NULL) return;
  else {
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
  }
}

/* Height of the tree */
int Height(struct node* root) {
  if(root == NULL) return 0;
  else {
    int lh = 1 + Height(root->left);
    int rh = 1 + Height(root->right);

    if(lh>=rh) return lh;
    else return rh;
  }
}


int main() {
  struct node* root = NULL;

  root = Insert(root, 4);
  root = Insert(root, 2);
  root = Insert(root, 6);
  root = Insert(root, 8);
  root = Insert(root, 10);
  root = Insert(root, 12);

  Inorder(root);

  int height = 0;
  height = Height(root);

  printf("Height of the tree is %d\n", height);

  return 0;
}

