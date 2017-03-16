/* Problem1: Describe how you can implement 3 stacks
 * using one array
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * So the idea is we divide the stack into 
 * three equal parts. Those 3 parts represent
 * the 3 stacks on the array
 */
struct Stack {
  int *arr;
  int top1;
  int top2;
  int top3;
  int size1;
  int size2;
  int size3;
  int total_size;
};

/* Given the size of the array (total
 * stack space), initialize the stack
 */
struct Stack* initStack(int size) {
  struct Stack* stack = malloc(sizeof(struct Stack));
  stack->arr = malloc(sizeof(int) * size); //Allocate the stack space
  stack->total_size = size;

  /* Bless the individual stacks some space */
  stack->size1 = size/3;
  stack->size2 = size/3;
  stack->size3 = size/3;

  /* Get the starting point for the stacks right */
  stack->top1 = -1;
  stack->top2 = (size/3) - 1;
  stack->top3 = (2*(size/3)) - 1; 

  /* Print the stack information */
  printf("Total Stack Space is  -- %d\n", stack->total_size);
  printf("\n");
  printf("Stack 1:\n");
  printf("\t Stack 1 size is :%d\n", stack->size1);
  printf("\t Stack 1 top is :%d\n",stack->top1);
  printf("Stack 2:\n");
  printf("\t Stack 2 size is :%d\n", stack->size2);
  printf("\t Stack 3 top is :%d\n",stack->top2);
  printf("Stack 3:\n");
  printf("\t Stack 3 size is :%d\n", stack->size3);
  printf("\t Stack 3 top is :%d\n",stack->top3);

  return stack;
}

/*
 * isStackFull ?
 */
bool isStackFull(struct Stack* stack, int id) {
    if(id == 1) {
        return(stack->top1>=stack->size1);
    }
    else if(id == 2) {
      return(stack->top1>=stack->size1);
    }
    else if(id == 3) {
      return(stack->top1>=stack->size1);
    }
    else {
      printf("Wrong stack ID\n");
      return false; //Wrong stack ID
    }
}

/*
 * isStackEmpty?
 */
bool isStackEmpty(struct Stack* stack, int id) {
  if(id == 1) {
    return(stack->top1<=-1);
  }
  else if(id == 2) {
    return(stack->top2<=(((stack->total_size)/3) - 1));
  }
  else if(id == 3) {
    return(stack->top3<=(2*((stack->total_size)/3) -1));
  }
  else {
    printf("Wrong stack ID\n");
    return false;
  }
}

/*
 * Push into the Stack1
 */
void Push1(struct Stack* stack, int item) {
}

int main() {
  /* Init stack space of 12 units */
  struct Stack* stack = initStack(12);

  return 0;
}
