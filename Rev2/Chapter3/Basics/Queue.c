/* Implement basic queue primitives */
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

struct Queue {
  struct node* head;
  struct node* tail;
};

/* Queue Init */
struct Queue* qInit() {
  struct Queue* queue = malloc(sizeof(struct Queue));
  queue->head = NULL;
  queue->tail = NULL;
  return queue;
}

/* Create a new Node */
struct node* createNode(int item) {
  struct node* newNode = malloc(sizeof(struct node));
  if(newNode == NULL) {
    printf("Couldn't allocate a new node\n");
    return NULL;
  }
  newNode->data = item;
  newNode->next = NULL;
  return newNode;
}

/* Insert a new node at the end */
void Enque(struct Queue* queue, int item) {
  printf("Inserting %d into the queue \n", item);
  struct node* temp  = createNode(item);
  if(queue->head == NULL) {
    queue->head = temp;
    queue->tail = temp;
    return;
  }
  /* Insert at the queue at the end */
  queue->tail->next = temp;
  queue->tail = temp;
}

/* Deque a node from the list */
void Deque(struct Queue* queue) {
  if(queue == NULL) {
    printf("Queue is empty!\n");
    return;
  }
  printf("\n Element being dequed is %d\n", queue->head->data);
  queue->head = queue->head->next;
}

/* Printer */
void printer(struct Queue* queue) {
  printf("\n*** Printing the queue ***\n");
  struct node* curr = queue->head;
  while(curr->next != NULL) {
    printf("%d->", curr->data);
    curr = curr->next;
  }
  printf("%d\n", curr->data);
}

int main() {
  struct Queue* queue  = NULL;
  queue = qInit();

  Enque(queue, 1);
  Enque(queue, 2);
  Enque(queue, 3);
  Enque(queue, 4);
  Enque(queue, 5);
  
  printer(queue);

  Deque(queue);
  Deque(queue);
  Deque(queue);
  Deque(queue);

  printer(queue);

  return 0;
}
