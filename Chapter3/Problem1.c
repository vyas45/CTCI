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
  if(isStackFull(stack, 1)) {
    printf("Overflow\n");
    return;
  }
  stack->top1++;
  printf("Pushing %d into stack1 at %d\n", item, stack->top1);
  stack->arr[stack->top1] = item;
}


/*
 * Push into the Stack2
 */
void Push2(struct Stack* stack, int item) {
  if(isStackFull(stack, 2)) {
    printf("Overflow\n");
    return;
  }
  stack->top2++;
  printf("Pushing %d into stack2 at %d\n", item, stack->top2);
  stack->arr[stack->top1] = item;
}

/*
 * Push into the Stack3
 */
void Push3(struct Stack* stack, int item) {
  if(isStackFull(stack, 3)) {
    printf("Overflow\n");
    return;
  }
  stack->top3++;
  printf("Pushing %d into stack3 at %d\n", item, stack->top3);
  stack->arr[stack->top3] = item;
}

/*
 * Pop from the first stack
 */
void Pop1(struct Stack* stack) {
  if(isStackEmpty(stack, 1)) {
    printf("Underflow\n");
    return;
  }
  printf("Popping %d from the stack1\n", stack->arr[stack->top1]);
  stack->top1--;
}

/*
 * Pop from the second stack
 */
void Pop2(struct Stack* stack) {
  if(isStackEmpty(stack, 2)) {
    printf("Underflow\n");
    return;
  }
  printf("Popping %d from the stack2\n", stack->arr[stack->top2]);
  stack->top2--;
}

/*
 * Pop from the third stack
 */
void Pop3(struct Stack* stack) {
  if(isStackEmpty(stack, 3)) {
    printf("Underflow\n");
    return;
  }
  printf("Popping %d from the stack3\n", stack->arr[stack->top3]);
  stack->top3--;
}

/*
 * Print the entire stack
 */
 void printer(struct Stack* stack) {
   int topper = -1;
   int i = 0;

   printf("-------- Printing the stacks ---------\n");
   printf("\n Stack1 :-> \n");
   for(i=0; i<stack->top1; i++)
      printf("%d\n ", stack->arr[stack->top1]);

   printf("\n Stack2 :-> \n");
   for(i=(stack->total_size/3) - 1; i<stack->top2; i++)
     printf("%d\n ", stack->arr[stack->top2]);

   printf("\n Stack3 :-> \n");
   for(i=(2*(stack->total_size/3)) - 1; i<stack->top3; i++)
     printf("%d\n ", stack->arr[stack->top3]);

 }

int main() {
  /* Init stack space of 12 units */
  struct Stack* stack = initStack(12);

  Push1(stack, 1);
  Push1(stack, 2);
  Push1(stack, 3);
  Push2(stack, 4);
  Push2(stack, 5);
  Push2(stack, 6);
  Push3(stack, 7);
  Push3(stack, 8);
  Push3(stack, 9);

  Pop1(stack);
  Pop2(stack);
  Pop3(stack);

  printer(stack);

  return 0;
}
