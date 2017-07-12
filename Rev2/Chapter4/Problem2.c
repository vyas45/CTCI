/* Given a sorted array create a BST from it */
#include <stdio.h>
#include <stdlib.h>


/* Each node of the BST */
struct node {
  int data;
  struct node* left;
  struct node* right;
};


/* Create a new node */
struct node* createNode(int item) {
  struct node* newNode = malloc(sizeof(struct node));
  if(newNode == NULL) {
    printf("Couldn't allocate a new node\n");
    return newNode;
  }
  /* Instantiate the node */
  newNode->data = item;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

/* Create a BST from array */
struct node* createBST(int arr[], int low, int high) {
  if(low>high) return NULL;
  else {
    int mid = (low+high)/2;
    struct node* root = createNode(arr[mid]);
    root->left = createBST(arr, low, mid-1);
    root->right = createBST(arr, mid+1, high);
    return root;
  }
}

/* Inorder traversal */
void Inorder(struct node* root) {
  if(root == NULL) return;
  else {
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
  }
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int size = sizeof(arr)/sizeof(int);

  struct node* root = NULL;

  root = createBST(arr, 0, size-1);

  /* Print the tree */
  Inorder(root);

  return 0;
}
