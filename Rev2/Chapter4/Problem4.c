/*
 * Is binary tree balanced
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};

/* Create a new Node */
struct node* newNode(int data)
{
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

/* Height of the binary tree */
int height(struct node* root) {
	if(root == NULL) return 0;
	else {
		int lh = height(root->left);
		int rh = height(root->right);

		if(lh>=rh) return(lh+1);
		else return(rh+1);
	}
}

bool isBalanced(struct node* root) {
	if(root == NULL) return true;
	else {
		int lh = height(root->left);
		int rh = height(root->right);

	  if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right))
				return true;
		return false;
	}
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);

    if(isBalanced(root))
      printf("Tree is balanced");
    else
      printf("Tree is not balanced");

    getchar();
    return 0;
}
