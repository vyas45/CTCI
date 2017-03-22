/*
 * Problem3: Create linked list for every depth in a binary tree
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

/* Defining the queue */
/* Each queue node  is a tree node */
struct qNode {
  /*
   * Each node in the queue needs to be
   * holding a tree node
   */
  struct node* tNode;
  struct qNode* next;
};

/* Defining the queue data structure */
struct Queue {
  struct qNode* head;
  struct qNode* tail;
};

/* Init a queue */
struct Queue* initQueue() {
  struct Queue* q = malloc(sizeof(struct Queue));
  q->head = NULL;
  q->tail = NULL;
  return q;
}

/* Insert an element into the queue 
 * This element is going to be of tree node 
 * type
 * */
void enque(struct Queue* q, struct node* tnode) {
  struct qNode *newNode = malloc(sizeof(struct qNode));
  newNode->tNode = tnode;
  newNode->next = NULL;
  /* If it is the first element */
  if(q->head == NULL) {
    q->head = newNode;
    q->tail = newNode;
    return;
  }
  /* Otherwise just push it at the rear end */
  q->tail->next = newNode;
  q->tail = newNode;
}

/* Remove an element from the queue 
 * The element returned out is the tree node
 * at the front of the queue
 */
struct node* deque(struct Queue* q) {
  if(q->head == NULL) {
    printf("Queue is empty\n");
    return NULL;
  }
  struct node* retNode = q->head->tNode;
  q->head = q->head->next; //Remove the first one in queue
  return retNode; //return the tree node at the head
}

/*
 * Return if the queue is empty or not
 */
bool isQueueEmpty(struct Queue* q) {
  return(q->head == NULL);
}

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

/* BFS on a tree */
void BFS(struct node* root) {
  struct Queue* q = initQueue();
  printf("Init the queue\n");
  struct node* u = NULL;
  struct node* v = NULL;
  struct node* level[10] = {0}; //This is the level array for every node
  int iLevel = -1; //Starting level
  int i = 0;

  enque(q, root); //enqueu the root node
  //level[root] = iLevel++;
  /* Keep going till the queue is not empty */
  while(!isQueueEmpty(q)) {
    u = deque(q);
    printf("%d -->  ", u->data);
    //If there is a left child enque it
    if(u->left) {
      enque(q, u->left);
      //level[u->left] = level[u] + 1;
    }
    if(u->right) {
      enque(q, u->right);
      //level[u->right] = level[u] + 1 ;
    }
  }
  for(i=0; i<10; i++) {
    printf("The level for node %d is level[i]", level[i]->data);
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

  BFS(root);

  printf("\n");

  return 0;
}
