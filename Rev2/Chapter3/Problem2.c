/* Implement a stack with StackMin() - returns minumum value on stack */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/* Define the structture for stack */
struct Stack {
    int *arr; //Array to hold values
    int *minArr; //a corresponding array that is going to hold the min value
    int size; //size of the stack
    int top; //pointer to top of the stack
};

/* Init the stack */
struct Stack* stackInit(int size) {
    struct Stack* stack = malloc(sizeof(struct Stack));
    stack->arr = calloc(size, sizeof(int));
    stack->minArr = calloc(size, sizeof(int));
    stack->size = size;
    stack->top = -1;
    
    /* need to init the min array with arbitarly large values */
    int i = 0;
    for(i=0; i<size; i++)
        stack->minArr[i] = 7777;
    return stack;
}

bool isStackFull(struct Stack* stack) {
    return(stack->top == (stack->size)-1);
}
bool isStackEmpty(struct Stack* stack) {
    return(stack->top == -1);
}


void updateMinArr(struct Stack* stack, int item) {
    /* if it is the first element */
    if( ((stack->top) - 1) == -1 )
        stack->minArr[stack->top] = item;
    /* Appropriately update the minArr */
    else {
        if(stack->arr[(stack->top) - 1] < item)
            stack->minArr[stack->top] =  stack->arr[(stack->top) - 1];
        else
            stack->minArr[stack->top] = item;
    }
}

/* Push an element into the stack */
void Push(struct Stack* stack, int item) {
    if(stack == NULL) {
        printf("Stack not init!!\n");
        return;
    }

    if(isStackFull(stack)) {
        printf("Stack Overflow!!\n");
        return;
    } 
 
    /* Insert element into the stack */
    stack->top++;
    stack->arr[stack->top] = item;

    /* update the min array on a push */
    updateMinArr(stack, item);
}

/* Pop element from the stack */
void Pop(struct Stack* stack) {
    if(stack == NULL) {
        printf("Stack not init\n");
        return;
    }
    if(isStackEmpty(stack)) {
        printf("Underflow!!\n");
        return;
    }
    printf("Element being popped is %d\n", stack->arr[stack->top]);
    stack->top--;
}

/* getMin() -- return the min element */
void getMin(struct Stack* stack) {
    if(isStackEmpty(stack)) {
        printf("Stack is empty!!\n");
        return;
    }
    printf("Top is at %d\n", stack->top);
    printf("Minimum element on stack is %d\n", stack->minArr[stack->top]);
}

/* Print the stack */
void printer(struct Stack* stack) {
    printf("\n\n******* STACK PRINT *******\n\n");
    int i = 0;
    for(i=(stack->top); i>=0; i--)
        printf("%d\n", stack->arr[i]);

}

int main() {
    struct Stack* stack = stackInit(4);

    Push(stack, 10);
    Push(stack, 4);
    Push(stack, 6);
    Push(stack, 1);

    printer(stack);

    getMin(stack);

    Pop(stack);
    getMin(stack);
    Pop(stack);
    getMin(stack);
    Pop(stack);
    getMin(stack);
    Pop(stack);
    getMin(stack);
    Pop(stack);
    getMin(stack);
    Pop(stack);
    getMin(stack);


   return 0;
} 
