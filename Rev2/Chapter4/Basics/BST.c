/* Binary Search Tree fundamentals */
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

/* Check if a node exists in the tree */
bool isNode(struct node* root, int item) {
  /* If tree is empty or reached the end */
  if(root == NULL) return false;
  else {
    if(root->data == item) return true;
    else if(root->data > item) return(isNode(root->left, item));
    else return(isNode(root->right, item));
  }
}


/* Delete a node from the tree */
struct node* Delete(struct node* root, int item) {
  if(root == NULL) {
    printf("did not find element\n");
    return root;
  }
  else {
  /* Algorithm to delete a node from the tree */
    /* Found the item */
    if(root->data == item) {
      printf("Found the node %d\n", root->data);
      struct node* rootl = root->left;
      root = root->right;
      struct node* curr = root;
      while(curr->left != NULL) curr = curr->left;
      curr->left = rootl;
      return root;
    }
    else if(root->data > item) return(Delete(root->left, item));
    else return(Delete(root->right, item));
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


int main() {
  struct node* root = NULL;

  root = Insert(root, 4);
  root = Insert(root, 2);
  root = Insert(root, 6);

  Inorder(root);
  printf("\n");

  if(isNode(root, 2))
    printf("Node 2 exists in the tree\n");
  else
    printf("Node 2 doesn't exist in the tree\n");

  if(isNode(root, 10))
    printf("Node 10 exists in the tree\n");
  else
    printf("Node 10 doesn't exist in the tree\n");


  Insert(root, 10);
  Inorder(root);
  printf("\n");
  if(isNode(root, 10))
    printf("Node 10 exists in the tree\n");
  else
    printf("Node 10 doesn't exist in the tree\n");

  /* Delete a node from the tree */
  Delete(root, 10);

  //Inorder(root);
  printf("\n");

  return 0;
}
