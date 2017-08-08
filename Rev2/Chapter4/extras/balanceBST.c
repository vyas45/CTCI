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

/* Inorder traversal of the tree */
void Inorder(struct node* root, int arr[]) {
  static int index  = 0;
  /* If the tree is empty just return */
  if(root == NULL) return;
  else {
    Inorder(root->left, arr);
    //printf("%d ",root->data);
    arr[index] = root->data;
    index = index+1;
    Inorder(root->right, arr);
  }
}

int countNodes(struct node* root) {
  if(root == NULL) return 0;
  else {
    if(root->left == NULL && root->right == NULL) return 1;
    else 
      return(1 + countNodes(root->left) + countNodes(root->right));
  }
}

struct node* arrToBST(int arr[], int low, int high) {
    if(low>high) return NULL;
    else {
      int mid = (low+high)/2;
      struct node* root = createNode(mid);
      root->left = arrToBST(arr, low, mid-1);
      root->right = arrToBST(arr, mid+1, high);
      return root;
    }

}

int main() {
  struct node* root = NULL;
  int i = 0;

  root = Insert(root, 4);
  root = Insert(root, 3);
  root = Insert(root, 2);
  root = Insert(root, 1);

  int count = countNodes(root);
  printf("Count is %d\n", count);

  int *arr = malloc(sizeof(int) * count);

  Inorder(root, arr);

  for(i = 0; i<count; i++)
    printf("%d ", arr[i]);

  printf("\n");
  struct node* root1 = NULL;
  root1 = arrToBST(arr, 0, count-1);

  return 0;
}
