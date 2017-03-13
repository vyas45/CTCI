/*
 * Remove duplicates from the Linked List
 * Prereq : Implementing basic linked list primitives
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

/* Delete a specific node */
void DeleteNode(struct node** head, int item) {
  struct node * curr = *head;

  if(*head == NULL) {
    printf("List is empty\n");
    return;
  }
  /* Head needs to be chopped off :x */
  if(curr->data == item) {
    *head =  curr->next;
    return;
  }

  /* Search the item in the list and get rid of it */
  while(curr->next!=NULL && curr->next->data!=item) {
    curr = curr->next;
  }
  if(curr->next == NULL) {
    printf("Element not found \n");
    return;
  }
  else {
    curr->next = curr->next->next;
    free(curr->next);
  }
}

/* Remove Duplicates from the linked list */
void RemoveDuplicates(struct node* head) {
  struct node *slow = head;
  struct node *fast = NULL;

  while(slow->next!=NULL) {
    fast = slow;
    while(fast->next!=NULL) {
      if(slow->data == fast->next->data) {
        printf("Found duplicate for %d \n",fast->next->data); 
        fast->next = fast->next->next;
      }
      else {
        fast = fast->next; //Move the fast pointer
      }
    }
    slow = slow->next; //Move the slow pointer
  }
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

int main() {
  struct node* head = NULL;

  InsertEnd(&head, 1);
  InsertEnd(&head, 2);
  InsertEnd(&head, 3);
  InsertEnd(&head, 4);

  InsertFront(&head, 5);
  InsertFront(&head, 4);
  InsertFront(&head, 3);
  InsertFront(&head, 2);
  InsertFront(&head, 4);
  InsertFront(&head, 8);

  printer(head);

  RemoveDuplicates(head);
  printer(head);

}
