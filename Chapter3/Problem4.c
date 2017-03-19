/*
 * Implement a queue using 2 stacks 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Define the structure for the stack */
struct Stack {
  int *arr;
  int top;
  int size;
};

/* Initialize the stack */
struct Stack* stackInit(int size) {
  struct Stack* stack = malloc(sizeof(struct Stack));
  stack->size = size;
  stack->top = -1;
  stack->arr = malloc(sizeof(int) * size);
  return stack;
}

/* Check if the stack is full */
bool isStackFull(struct Stack* stack) {
  return (stack->top >= stack->size);
}

/* Check of the stack is empty */
bool isStackEmpty(struct Stack* stack) {
  return (stack->top < 0);
}
/* Push an element onto the stack */
void Push(struct Stack* stack, int item) {
  if(isStackFull(stack)) {
    printf("Overflow\n");
    return;
  }
  /* Increment the top and then push */
  stack->top++;
  printf("Inserting %d at %d\n", item, stack->top);
  stack->arr[stack->top] = item;
}

/* Pop and return element from the stack */
int Pop(struct Stack* stack) {
  if(isStackEmpty(stack)) {
    printf("Underflow\n");
    return -777;
  }
  int pop_item = -1;
  /* pop the item and then decrement the top */
  pop_item = stack->arr[stack->top--];
  return pop_item;
}

/* Print the stack elements */
void printer(struct Stack* stack) {
  int topper = stack->top;
  int i = 0;
  if(stack->top == -1) {
    printf("The stack is empty\n");
    return;
  }
  printf("Top is %d\n", topper);
  for(i=0;i<=topper;i++) 
    printf("%d\n", stack->arr[i]);
}
/*
   while(topper-->-1) {
   printf("topper is %d\n", topper);
   }
   */
int main() {
  struct Stack* stack = NULL;
  int popper = 0;

  /* Init the stack */
  stack = stackInit(5);

  /* Push Elements into the stack */
  Push(stack, 5);

  printer(stack);



  return 0;
}

