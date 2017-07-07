/* Implement stack of stacks */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Define the SoS */
struct Stack {
  int **arr; //Holds the stack of stacks
  int *top; //holds the top for each stack
  int size; //max size of the stack of stacks
  int index; //stack index number
  int max_index; //max number of stacks
};

/* Initialize the stacks */
struct Stack* initStacks(int num, int size) {
  int i = 0;
  struct Stack* stack = malloc(sizeof(struct Stack));

  /* Allocate the stack of stacks */
  stack->arr  = malloc(num * sizeof(int));//Allocate the "num" stacks
  for(i=0; i<num; i++)
    stack->arr[i] = malloc(size * sizeof(int)); //Allocate space for each stack

  /* Allocate the index array */
  stack->top = malloc(num * sizeof(int));
  for(i=0; i<num; i++)
    stack->top[num] = -1; //Initialize the tops of each stack

  /* Allocate the remaining sizes */
  stack->size = size-1; //Max size of each stack
  stack->index = 0; //Starting index  of the stacks
  stack->max_index = num-1; //Maximum number of stacks

  return stack;
}

/* Return if we are out of space */
bool isStackFull(struct Stack* stack) {
  return ((stack->top[stack->index] == stack->size) && stack->index == stack->max_index);
}

/* Get index of where to push */
int getIndex(struct Stack* stack) {
  /* If the current top has reached max return the next stack index */
  if(stack->top[stack->index] > stack->size) {
    stack->top[stack->index] = -1;
    stack->index++;
    printf("New stack index is %d\n", stack->index);
  }
  return stack->index;
}

/* Push an element into the stack */
void Push(struct Stack* stack, int item) {
  if(isStackFull(stack)) {
    printf("Stack Overflow!!\n");
    return;
  }
  int index = getIndex(stack);
  printf("Stack index is %d\n", index);
  printf("Stack top is %d\n",stack->top[index]);
  printf("Pushed %d in stack#%d at top#%d\n", item, index, stack->top[index]);
  stack->arr[index][stack->top[index]++] = item;
}

int main() {
  struct Stack* stack;

  stack = initStacks(4, 4);

  /* Push elements */
  Push(stack, 1);
  Push(stack, 2);
  Push(stack, 3);
  Push(stack, 4);
  Push(stack, 5);
  Push(stack, 6);
  Push(stack, 7);
  Push(stack, 8);
  Push(stack, 9);
  Push(stack, 10);
  Push(stack, 11);
  Push(stack, 12);
  Push(stack, 13);
  Push(stack, 14);
  Push(stack, 15);
  Push(stack, 16);
  Push(stack, 4);
  Push(stack, 4);
  Push(stack, 4);
  Push(stack, 4);
  Push(stack, 4);
  Push(stack, 4);
  Push(stack, 4);
  Push(stack, 4);

  return  0;
}
