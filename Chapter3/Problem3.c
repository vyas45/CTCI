/*
 * Stack of Plates: Implement a stack of plates such that if the stack 
 * runs over then we push into the new stack
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 4
#define MAX_NUM 3 

/*
 * The idea is to have a 2d array to hold the 
 * multiple stacks together
 */
struct Stack {
  int arr[MAX_SIZE][MAX_NUM];
  int top;
  int num; //Update this when the current stack is empty/full
};

struct Stack* initStack() {
  int i, j = 0;
  struct Stack *stack;

  //Allocate space for ther stack
  stack = malloc(sizeof(struct Stack));
  //Init everything
  for(i=0; i<MAX_NUM; i++) {
      for(j=0; j<MAX_SIZE; j++) {
        stack->arr[i][j] = 777;
      }
  }
  stack->top = -1;
  stack->num = 0;//The current stack we are at
  return stack;
}

/*
 * Push an element into the stack of Stacks
 */
void Push(struct Stack* stack, int item) {
  /*
   * Check if we are are out of the current stack
   * If we are, check if we have more stacks left
   * if no more stacks left, need to quit
   */
  if(stack->top == MAX_SIZE-1) {
    if(stack->num == MAX_NUM-1) {
      printf("No more stacks left\n");
      return;
    }
    stack->num++;//Still have stacks left, get to the next one
    stack->top = -1; //Need to reset the top
    printf("Moving onto stack %d\n", stack->num);
  }
  /* All good to push element in */
  stack->top++;
  stack->arr[stack->num][stack->top] = item;
  printf("Pushed %d at %d in stack %d\n", stack->arr[stack->num][stack->top], stack->top, stack->num);
}

/*
 * Pop an element from the stack of stacks
 */
void Pop(struct Stack* stack) {
  /*
   * Pop an element from the current stack
   * If we hit the low, then move on to the previous stack
   * If no more left we return back
   */
  if(stack->top == -1) {
    if(stack->num == 0) {
      printf("Out of stacks\n");
      return;
    }
    stack->num--; //Still got stuff to pop out
    stack->top = MAX_SIZE-1; //Need to reset the top
  }
  printf("Going to pop %d at %d from stack %d\n", stack->arr[stack->num][stack->top], stack->top, stack->num);
  stack->top--;
}

/* Printer */
void printer(struct Stack* stack) {
  int i, j = 0;

  for (i=0; i<MAX_NUM; i++) {
    for (j=0; j<MAX_SIZE; j++) { 
      printf("%d  ", stack->arr[i][j]);
    }
    printf("\n");
  }

  /* Print the stack of stacks */
  for(i=0; i<MAX_NUM; i++) {
    printf("\n\nPrinting info for stack #%d\n", i);
    for(j=MAX_SIZE-1; j>=0; j--) {
      printf(" arr[%d][%d] is %d\n",i, j, stack->arr[i][j]); 
    }
  }
}

int main() {
  struct Stack* stack = initStack();

  printer(stack);

  Push(stack, 1);
  Push(stack, 2);
  Push(stack, 3);
  Push(stack, 4);
  Push(stack, 5);
  Push(stack, 6);
  Push(stack, 8);
  Push(stack, 9);
  Push(stack, 10);
  Push(stack, 11);
  Push(stack, 12);
  Push(stack, 13);
  Push(stack, 14);
  Push(stack, 15);
  Push(stack, 16);
  Push(stack, 17);
  Push(stack, 18);
  Push(stack, 19);

  printer(stack);

  return 0;
}
