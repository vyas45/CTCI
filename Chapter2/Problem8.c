/*
 * Find out if a circular linked list has a loop
 * and return the pointer to the start of the loop
 *
 * input: A->B->C->D-E->C (the same C as earlier)
 * return: C
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

/* Allocate an new node with the data */
struct node* createNode(int item) {
  struct node* newNode = NULL;
  newNode = malloc(sizeof(struct node));
  newNode->data = item;
  newNode->next = NULL;
  return newNode;
}

/* Insert a newNode at the end of the list */
void InsertEnd(struct node** head, int item) {
  struct node* curr = *head;

  /* Create the new Node with the data passed in */
  struct node* newNode =  createNode(item);

  /* If it is an empty list to start with */
  if(*head == NULL) {
    *head = newNode; 
    return;
  }

  /* Iterate till the end of the list and append the newNode */
  while(curr->next!=NULL) {
    curr = curr->next;
  }
  curr->next = newNode;
}

/* Insert at the front of the array */
void InsertFront(struct node** head, int item) {
  struct node* newNode =  createNode(item);

  if(*head == NULL){
    *head = newNode;
    return;
  }
  /* Otherwise make it the head of the existing list */
  newNode->next = *head;
  *head  = newNode;
}

/* Print the linked list */
void printer(struct node* head) {
  struct node* curr = head;

  while(curr!=NULL) {
    printf("%d -->", curr->data);
    curr = curr->next;
  }
  printf("NULL\n");
}

/* getLooper() - get the starting point of the linked list loop */
struct node* getLooper(struct node* head) {
  if(head == NULL) return NULL; //Empty List passed in
  else {
    struct node* slow = head;
    struct node* fast = head;

    while(fast->next!=NULL) {
      slow = slow->next;
      fast = fast->next->next;
      if(slow==fast){
        printf("Loop found\n");
        return slow;
      }
    } 
  }
  printf("Didn't find a loop\n");
  return NULL; //No loop found
}

int main() {
  struct node* head = NULL;
  struct node* looper = NULL;

  InsertEnd(&head, 1);
  InsertEnd(&head, 2);
  InsertEnd(&head, 3);
  InsertEnd(&head, 4);

  /* Make 4 point to 2 , the <node> not the <value> only */
  head->next->next->next->next = head->next;
  //printer(head);

  /* Get the looper - starting node of the loop */
  looper = getLooper(head);
  printf("The loop starts at %d\n", looper->next->data);

  return 0;

}
