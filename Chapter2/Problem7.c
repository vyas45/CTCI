/*
 * Intersection: Find the intersection point of the
 * linked lists
 * Note: The linked lists intersect by reference not by value
 *
 *    1->2->3->4->5->6->NULL
 *        ^
 *        |
 *    8->9-
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

/* Print the linked list */
void printer(struct node* head) {
  struct node* curr = head;

  while(curr!=NULL) {
    printf("%d -->", curr->data);
    curr = curr->next;
  }
  printf("NULL\n");
}

/* Do the linked lists intersect */
bool Intersect(struct node* head1, struct node* head2) {
  if(head1 == NULL || head2 == NULL) return false;
  else {
    if(head1==head2) {
      return true;
    }
    return(Intersect(head1->next, head2->next));

  }
}

bool doIntersect(struct node* head1, struct node* head2) {
  struct node* curr1 = head1;
  struct node* curr2 = head2;
  int len1 = 0; //Length of the first linked list
  int len2 = 0; //Length of the second linked list
  int i = 0;
  bool result = false;

  while(curr1!=NULL) {
    len1++;
    curr1=curr1->next;
  }
  while(curr2!=NULL) {
    len2++;
    curr2=curr2->next;
  }

  curr1 = head1;
  curr2 = head2;

  if(len1 == len2)
      result = Intersect(curr1, curr2);
  else if(len1>len2) {
    for(i=0; i<(len1-len2); i++) {
      curr1 = curr1->next;
    }
    result = Intersect(curr1, curr2); //Call to check if anything same
  }
  else {
    for(i=0; i<(len2-len1); i++) {
      curr2 = curr2->next;
    }
    result = Intersect(curr1, curr2); //Call to check if anything same
  }
  return result;
}

int main() {
  struct node* head1 = NULL;
  struct node* head2 = NULL;

  /* Create the linked list structure as in description */
  InsertEnd(&head1, 1);
  InsertEnd(&head1, 2);
  InsertEnd(&head1, 3);
  InsertEnd(&head1, 4);
  InsertEnd(&head1, 5);

  /* Create head2 as 8->9->head1 */ 
  InsertEnd(&head2, 8);
  InsertEnd(&head2, 9);
  head2->next->next = head1->next->next; 

  printer(head1);
  printer(head2);

  if(doIntersect(head1, head2))
      printf("The lists intersect\n");
  else 
      printf("The lists do not intersect\n");

  return 0;
}
