/*
 * Given a binary tree, create linked lists from each level
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/* Each node on the binary tree */
struct node {
  int data;
  struct node* left;
  struct node* right;
};


/* Create a new node */
struct node* createNode(int item) {
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = item;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

/*
 * ********************************************
 * Tree Primitives
 * ********************************************
 */

/* Insert a node in the binary tree */
struct node* InsertNode(struct node* root, int item) {
  if(root == NULL) return(createNode(item));
  else {
    if(root->data >= item) {
      root->left = InsertNode(root->left, item);
    }
    else {
      root->right = InsertNode(root->right, item);
    }
    return root;
  }
}

/* Inorder traversal of the tree */
void Inorder(struct node* root) {
  if(root == NULL) return;
  else {
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
  }
}

/*
 * ********************************************
 * Queue Primitives
 * ********************************************
 */

/*
 * A queue is maintained as a linked list of nodes
 */
struct qnode {
  struct node* data;
  struct qnode* next;
};

struct queue {
  struct qnode* head;
  struct qnode* tail;
};

/* queue Initialization */
struct queue* qInit() {
  struct queue *q = (struct queue*)malloc(sizeof(struct queue));
  q->head = NULL;
  q->tail = NULL;
  return q;
}

/* Create a node of type qnode */
struct qnode* createqNode(struct node* node) {
  struct qnode* newqNode = malloc(sizeof(struct qnode));
  if(newqNode == NULL) return NULL;
  newqNode->data = node;
  newqNode->next = NULL;
  return newqNode;
}

/* Check if the queue is empty */
bool isQEmpty(struct queue* q) {
  return (q->head == NULL);
}

/* Enqueue a node */
void Enque(struct queue* q, struct node* item) {
  struct qnode* temp = createqNode(item);
  /* First element in the queue */
  if(q->head == NULL) {
    q->head = temp;
    q->tail = temp;
    return;
  }
  /* Insert a node at the end of the queue */
  q->tail->next = temp;
  q->tail = temp; //Make the new qnode the tail
}

/* Deque a node from the queue */
struct node* Deque(struct queue* q) {
  if(isQEmpty(q)) return NULL;
  else {
    struct node* ret = q->head->data; //Return the element at the head
    q->head = q->head->next; //Push ahead the head
    return ret;
  }
}

int main() {
  struct node* root = NULL;

  /* Insert a few nodes */
  root = InsertNode(root, 6);
  root = InsertNode(root, 4);
  root = InsertNode(root, 8);
  root = InsertNode(root, 2);
  root = InsertNode(root, 5);
  root = InsertNode(root, 7);
  root = InsertNode(root, 9);

  /* Inorder traversal */
  //Inorder(root);

  /* Init the queue */
  struct queue *q = qInit();
  struct node*  u = NULL;
  struct node*  v = NULL;
  u = root;
  Enque(q, u);
  while(!isQEmpty(q)) {
    v = Deque(q);
    printf("%d ", v->data);
    if(v->left) {
      Enque(q, v->left);
    }
    if(v->right) {
      Enque(q, v->right);
    }
  }
  return 0;
}
