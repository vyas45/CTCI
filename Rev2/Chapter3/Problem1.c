/* Implement 3 stacks using one array */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Define the structure for stack */
struct Stack {
  int *arr;
  int top1;
  int top2;
  int top3;
  int size;
};

/* Init the stack */
struct Stack* stackInit(int size) {
  struct Stack* stack = malloc(sizeof(struct Stack));
  stack->top1 = -1;
  stack->top2 = (size/3) - 1;
  stack->top3 = (2 * (size/3)) - 1;
  stack->size = size;
  return stack;
}

/* Check if a stack is full */
bool isStackFull(struct Stack* stack, int num) {
  switch(num) {
    case1: return(stack->top1 == ((stack->size)/3) - 1);
    case2: return(stack->top2 == (2 * ((stack->size)/3)) - 1);
    case3: return(stack->top3 == ((stack->size)) - 1);
    default: printf("Wrong stack id entered\n");
             return true;
  }
}

/* Check if a stack is full */
bool isStackEmpty(struct Stack* stack, int snum) {
  switch(snum) {
    case1: return(stack->top1 == -1);
    case2: return(stack->top2 == ((stack->size)/3) - 1);
    case3: return(stack->top3 == (2 *((stack->size)/3)) - 1);
    default: printf("Wrong stack id entered\n");
             return true;
  }
}

/* Push element into a specific stack */
void Push(struct Stack* stack, int item, int snum) {
  if(stack == NULL) {
    printf("Stack doesn't exist\n");
    return;
  }
  /* Check if the stack is full */
  if(isStackFull(stack, snum)) {
    printf("Overflow on Stack #%d\n!!", snum);
    return;
  }
  /* All clear, push data in */
  switch(snum) {
    case 1: stack->top1++;
            stack->arr[stack->top1] = item;
            return;
    case 2: stack->top2++;
            stack->arr[stack->top2] = item;
            return;
    case 3: stack->top3++;
            stack->arr[stack->top3] = item;
            return;
    default: printf("Wrong stack id given\n");
             return;
  }
}

/* Pop an element from the stack */
int Pop(struct Stack* stack, int snum) {
  if(stack == NULL) {
    printf("Stack doesn't exist!!\n");
    return -777;
  }
  if(isStackEmpty(stack, snum)) {
      printf("Stack is empty!!\n");
      return -777;
  }
  int retVal = 0; //Hold the value to be popped out
  switch(snum) {
    case 1: retVal = stack->arr[stack->top1];
            stack->top1--;
            return retVal;
    case 2: retVal = stack->arr[stack->top2];
            stack->top2--;
            return retVal;
    case 3: retVal = stack->arr[stack->top3];
            stack->top3--;
            return retVal;
    default: printf("Wrong stack id entered\n");
             return -777;
  }
}

int main() {
  struct Stack* stack = NULL;

  /* Init the stack */
  stack = stackInit(9);

  /* Push elements into the stack */
  Push(stack, 1, 1); 
  Push(stack, 2, 1); 
  Push(stack, 3, 1); 
  Push(stack, 4, 1); 
  Push(stack, 5, 2); 

  return 0;
}
