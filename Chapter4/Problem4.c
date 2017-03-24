/*
 * Check if a tree is balanced
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

/* Compute the height of the tree */
int height(struct node* root) {
  if(root == NULL) return 0;
  else {
    int lh = height(root->left);
    int rh = height(root->right);
    if(lh>=rh)
      return(lh+1);
    else
      return(rh+1);
  }
}

/*
 * Check if a tree is balanced
 */
bool isBalanced(struct node* root) {
  if(root == NULL) return true;
  else {
    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh-rh) <=1 &&
        isBalanced(root->left) &&
        isBalanced(root->right)) {
        return true;
    }
    return false;
  }
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

  /* Height of tree */
  int h = height(root); 
  printf("The height of tree is %d\n", h);

  if(isBalanced(root))
      printf("The tree is balanced\n");
  else
      printf("The tree is not balanced\n");
  return 0;
}
