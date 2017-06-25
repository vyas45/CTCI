/* Implement the basic stack primitives */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack {
  int *arr;
  int size;
  int top;
};

/* Create a new stack */
struct Stack* initStack(int size) {
  struct Stack* stack  = malloc(sizeof(struct Stack));
  stack->arr = malloc(sizeof(int) * size);
  stack->size = size;
  stack->top = -1;
  return stack;
}

/* isStackFull() */
bool isStackFull(struct Stack* stack) {
  printf("stack->top is %d\n", stack->top);
  printf("stack->size is %d\n", stack->size);
  return((stack->top) == (stack->size)-1);
}

/* isStackEmpty() */
bool isStackEmpty(struct Stack* stack) {
  return((stack->top) == -1);
}

/* Push item */
void Push(struct Stack* stack, int item) {
  if(isStackFull(stack)) {
    printf("Stack Overflow\n");
    return;
  }
  (stack->top)++;
  stack->arr[stack->top] = item;
  printf("Pushed %d into the stack\n", item);
}

/* Pop item from the stack */
int Pop(struct Stack* stack) {
  if(isStackEmpty(stack)) {
    printf("Underflow\n");
    return -777;
  }
  int retVal = stack->arr[stack->top];
  (stack->top)--;
  return retVal;
}

/* Peek item from the stack */
void Peek(struct Stack* stack) {
  printf("\n\nPeekd element is %d\n", stack->arr[stack->top]);
}

/* Print the stack */
void printStack(struct Stack* stack) {
  int i = 0;
  printf("\n\n Printing the stack \n\n");
  for(i=(stack->top) ;i>=0; i--)
    printf("%d\n", stack->arr[i]);
  printf("\n");
}


int main() {
  struct Stack* stack = NULL;

  stack = initStack(4);

  Push(stack, 1);
  Push(stack, 2);
  Push(stack, 3);
  Push(stack, 4);
  Push(stack, 5);

  int pop;
  pop = Pop(stack);
  printf("Item popped from the stack is %d\n", pop);

  Peek(stack);


  printStack(stack);

  return 0;
}
