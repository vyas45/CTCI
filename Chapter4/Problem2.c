/* Problem2: Given a sorted array, create a BST from it
 * The solution would involve recursively creating left and
 * right nodes from the mid of the array
 */
#include <stdio.h>
#include <stdlib.h>

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

/* Create a BST from the sorted array */
struct node* createBST(int arr[], int low, int high) {
  if(low>high) return NULL;

  int mid = (low+high)/2;
  struct node* root = createNode(arr[mid]);
  root->left = createBST(arr, low, mid-1);
  root->right = createBST(arr, mid+1, high);
  return root;
}

/* Inorder traversal of the tree */
void InOrder(struct node* root) {
  if(root == NULL) return;
  else {
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
  }
}


int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int size = sizeof(arr)/sizeof(int);
  struct node* root = NULL;

  root = createBST(arr, 0, size-1);

  printf("Done creating BST\n");

  InOrder(root);

  return 0;
}
