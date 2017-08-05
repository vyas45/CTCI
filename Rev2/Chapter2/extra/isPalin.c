/*
 * Check if the given linked list is palindrome
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Each linked list node */
struct node {
  int data;
  struct node* next;
};


/* Create a new Node */
struct node* createNode(int data) {
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  if(temp == NULL) {
    printf("Cannot allocate node\n");
    return NULL;
  }
  temp->data = data;
  temp->next = NULL;
  return temp;
}

/* Insert a new Node at the end of the list */
void InsertNode(struct node** head, int item) {
  struct node* newNode = createNode(item);
  if(*head == NULL) {
    /* First element */
    *head = newNode;
    return;
  }
  struct node* curr = *head;
  /* Walk till the end */
  while(curr->next!=NULL) {
    curr = curr->next;
  }
  /* Insert the node */
  curr->next = newNode;
}

/* Insert a node at the head of the list */
void InsertFront(struct node** head, int item) {
  struct node* newNode = createNode(item);
  if(*head == NULL) {
    /* First element */
    *head = newNode;
    return;
  }
  /* Insert the node at the front */
  newNode->next = *head;
  *head = newNode;
}

/* Printer */
void printer(struct node* head) {
  struct node* curr = head;
  while(curr->next!=NULL) {
    printf("%d->", curr->data);
    curr = curr->next;
  }
  printf("%d\n", curr->data);
}
/* Reverse a list */
void Reverser(struct node* h1, struct node** h2) {
  if(h1 == NULL) {
    return;
  }
  else {
    Reverser(h1->next, h2);
    InsertNode(h2, h1->data);
  }
}
/* Check if it is a palindrome */
bool isPalin(struct node* head) {
  if(head == NULL)
      return true;
  else {
    struct node* h2 = NULL;
    struct node* h1 = head;
    Reverser(h1, &h2);
    printf("Second list is \n");
    printer(h2);

    while(h1!=NULL) {
      if(h1->data != h2->data) {
        return false; //Something different
      }
      h1 = h1->next;
      h2 = h2->next;
    }
    return true; // Reached here all good
  }
}

int main() {
  struct node* head = NULL;

  /* Insert the nodes */
  InsertNode(&head, 1);
  InsertNode(&head, 2);
  InsertNode(&head, 2);
  InsertNode(&head, 3);

  printer(head);

  if(isPalin(head))
    printf("It is a palindeome\n");
  else
    printf("It is not a palindrome\n");

  return 0;
}
