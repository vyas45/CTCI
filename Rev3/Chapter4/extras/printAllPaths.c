/* Print all paths on a binary tree */
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

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

/* Print the paths */
void printer(int arr[], int size) {
    int  i = 0;
    for(i=0; i<size; i++)
        printf("%d ", arr[i]);

    printf("\n***********\n");
}

/* Print all paths in a binary tree */
void printPathsRecur(struct node* root, int arr[], int index) {
    if(root == NULL) return;

    arr[index] = root->data;
    index = index+1;

    if(root->left == NULL
       && root->right == NULL) {
        printer(arr, index);
    }
    else {
        printPathsRecur(root->left, arr, index);
        printPathsRecur(root->right, arr, index);

    }


}


void printPaths(struct node* root) {
    if(root == NULL) return;
    else {
        int path[100];
        printPathsRecur(root, path, 0);
    }
}

int main() {
  struct node *root = createNode(10);
  root->left        = createNode(8);
  root->right       = createNode(2);
  root->left->left  = createNode(3);
  root->left->right = createNode(5);
  root->right->left = createNode(2);


  printf("The root is %d\n", root->data);

  /* Print inOrder */
  Inorder(root);
  printf("\n");

  /* Print Paths */
  printPaths(root);

  return 0;
}
