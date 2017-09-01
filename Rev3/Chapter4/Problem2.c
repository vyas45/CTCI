/*
 * Create a BST from a sorted array
 */

struct node {
  int data;
  struct node* left;
  struct node* right;
};

struct node* createNode(int data) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

struct node* arrToBST(int arr[], int low, int high) {
  if(low>high) return NULL;
  else {
    int mid = (low + high)/2;
    struct node* root = createNode(arr[mid]);
    root->left = arrToBST(arr, low, mid-1);
    root->right = arrToBST(arr, mid+1, high);
    return root;
  }
}
