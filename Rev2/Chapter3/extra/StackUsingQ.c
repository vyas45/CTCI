/* Implement stack using queue */
/*
 * To implement a stack using queue first we need to implement a queue
 *
 * Queue Primitives:
 * enque()
 * deque()
 * isEmpty()
 *
 * Once we have a queue we can have:
 * Push()
 * Pop()
 * Peek()
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Linked List Node */
struct node {
  int data;
  struct node* next;
};

/* Structure to represent a queue */
struct Queue {
  struct node* head; //head of the queue
  struct node* tail; //tail of the queue
};

/* Structure to represent a stack */
struct Stack {
  struct Queue* queue;
  int top;
  int size;
};

/* 
 *  QUEUE PRIMITIVES
 */

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

/* Initialize a queue */
struct Queue* qInit() {
  struct Queue* queue = malloc(sizeof(struct Queue));
  queue->head = NULL;
  queue->tail = NULL;
  return queue;
}

/* isQueueEmpty() - Return if the queue is empty */
bool isQueueEmpty(struct Queue* queue) {
  return (queue->head == NULL);
}

/* Enque a node in the queue */
void Enque(struct Queue* queue, int item) {
  if(queue == NULL) {
    printf("queue doesn't exist\n");
    return;
  }
  struct node* newNode = createNode(item);
  /* If it is the first item on the queue */
  if(queue->head == NULL) {
    queue->head = newNode;
    queue->tail = newNode;
    return;
  }
  /* Insert the element at the front of the queue
   * becuse we want to implement a stack
   */
  newNode->next = queue->head;
  queue->head = newNode;
}

/* Deque - get an element from the front of the queue */
int Deque(struct Queue* queue) {
  if(queue == NULL) {
    printf("Queue doesn't exist\n");
    return 777;
  }
  if(isQueueEmpty(queue)) {
    printf("The queue is empty!\n");
    return 777;
  }
  struct node* temp = queue->head; //Hold the top on a temp object
  int retVal = temp->data;
  queue->head = queue->head->next;
  free(temp); //Free the first element from the queue
  return retVal;
}

void qprinter(struct Queue* queue) {
  struct node* curr = queue->head;
  if(curr == NULL) {
    printf("Nothing to print here ! Queue Empty\n");
    return;
  }
  while(curr->next != NULL) {
    printf("%d->", curr->data);
    curr = curr->next;
  }
  printf("%d\n", curr->data);
}

/*
 *  STACK PRIMITIVES
 */
struct Stack* stackInit(int size) {
  struct Stack* stack = malloc(sizeof(struct Stack));
  stack->queue = qInit();
  stack->size = size;
  stack->top = -1;
  return stack;
}

/* Check if the stack is full */
bool isStackFull(struct Stack* stack) {
  return (stack->top == stack->size - 1);
}
/* Check if the stack is empty */
bool isStackEmpty(struct Stack* stack) {
  return (stack->top == -1);
}

void Push(struct Stack* stack, int item) {
  if(isStackFull(stack)) {
    printf("Stack Overflow!!\n");
    return;
  }
  /* Increment the top count */
  stack->top++;
  Enque(stack->queue, item); //Insert the element into the queue
  printf("Pushed %d at stack top %d\n", item, stack->top);
}

void Pop(struct Stack* stack) {
  if(isStackEmpty(stack)) {
    printf("Underflow\n");
    return;
  }
  /* Decrement the top */
  stack->top--;
  int retVal = Deque(stack->queue);
  printf("Element popped is %d\n", retVal);
}

/* Stack printer */
void stackPrinter(struct Stack* stack) {
  if(isStackEmpty(stack)) {
    printf("The stack is empty\n");
    return;
  }
  qprinter(stack->queue);
}

int main() {
  struct Queue* queue = qInit();

  /* Enque */
  Enque(queue, 1);
  Enque(queue, 2);
  Enque(queue, 3);
  Enque(queue, 4);

  /* Print the queue */
  qprinter(queue);
  int de = 0;
  de = Deque(queue);
  printf("Element dequed is %d\n", de);
  de = Deque(queue);
  printf("Element dequed is %d\n", de);
  de = Deque(queue);
  printf("Element dequed is %d\n", de);
  de = Deque(queue);
  printf("Element dequed is %d\n", de);
  de = Deque(queue);
  printf("Element dequed is %d\n", de);


  qprinter(queue);

  struct Stack* stack = stackInit(4);
  Push(stack, 1);
  Push(stack, 2);
  Push(stack, 3);
  Push(stack, 4);
  Push(stack, 5);

  stackPrinter(stack);

  Pop(stack);
  Pop(stack);
  Pop(stack);
  Pop(stack);
  Pop(stack);
  Pop(stack);
  Pop(stack);

  return 0;
}
