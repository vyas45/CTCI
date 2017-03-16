/*
 * Implement queue primitives
 * Linked List based implementation of a queue
 */

#include <stdio.h>
#include <stdlib.h>

/* Each node in a queue */
struct node {
  int data;
  struct node* next;
};

struct queue {
  struct node* head;
  struct node* tail;
};

/* Init the queue */
struct queue* initQueue() {
  struct queue* q = malloc(sizeof(struct queue));
  q->head = NULL;
  q->tail = NULL;
  return q;
}

/* Create a new node type */
struct node* createNode(int item) {
  struct node* newNode =  malloc(sizeof(struct node));
  newNode->data = item;
  newNode->next = NULL;
  return newNode;
}

/* Enque Routine 
 * Always enque at the tail end of the list 
 */
void Enqueue(struct queue* q, int item) {
  if(q == NULL) {
      printf("Invalid queue\n");
      return;
  }
  struct node* newNode = createNode(item);
  /* If it is the first element in the queu */
  if(q->head == NULL) {
    q->head = newNode;
    q->tail = newNode;
    printf("Inserted %d as the first node \n", item);
    return;
  }

  /* Otherwise insert at the tail */
  q->tail->next = newNode;
  q->tail = newNode;
  printf("Inserted %d at the tail \n", item);
}

/* Deque
 * Always deque from the front of the list 
 */
int Deque(struct queue* q) {
  if(q == NULL) {
    printf("Invalid queue\n");
    return -1;
  }
  /* There is nothing in the list */
  if(q->head == NULL) {
      printf("Queue Empty\n");
      return -1;
  }
  int retNode = q->head->data;
  q->head = q->head->next;

  printf("Dequeued %d from the list \n", retNode);
  return retNode;
}

/* Print the queue */
void printer(struct queue* q) {
  struct node* curr = q->head;
  while(curr!=NULL) { 
    printf("%d --> ", curr->data);
    curr = curr->next;
  }
  printf("NULL\n");
}

int main() {
  struct queue* q = initQueue();

  /* Enqueue */
  Enqueue(q, 1);
  Enqueue(q, 2);
  Enqueue(q, 3);
  Enqueue(q, 4);

  printer(q);

  /* Deque */
  Deque(q);
  Deque(q);
  Deque(q);
  Deque(q);
  Deque(q);
  Deque(q);
  Deque(q);

  Enqueue(q, 3);
  printer(q);

  return 0;
}
