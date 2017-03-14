/* 
 * Partition: Partition the linked list around value 'x', so that
 * all the nodes less than x come before nodes greater than or equal 
 * to x
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

/* Function To Partition around 'x' */
void Partition(struct node** head, int x) {
  struct node* curr = *head;
  struct node* tail = *head;
  int count = 0;

  /* Have tail pointing to the end of the list 
   * and insert the greater elements there */
  while(tail->next!=NULL) {
      tail = tail->next;
      count++;
  }

  /* Handle the head first */ 
  if(curr->data >= x) {
    printf("Curr->data for head is %d\n", curr->data);
    tail->next = createNode(curr->data);
    *head = curr->next;
    tail = tail->next;
  }
  
  while(curr->next!=NULL && count) {
    if(curr->next->data >= x) {
      struct node* temp = createNode(curr->next->data);
      tail->next = temp;
      tail = temp;
      curr->next = curr->next->next;
      /* If it is the head , update the head */
      if(*head) {
        *head = curr->next;
      }
      count = count -1;;
    }
    else {
      curr = curr->next;
      count = count-1;
    }
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

  InsertEnd(&head, 5);
  InsertEnd(&head, 10);
  InsertEnd(&head, 2);
  InsertEnd(&head, 1);

  InsertFront(&head, 8);
  InsertFront(&head, 5);
  InsertFront(&head, 3);

  printer(head);

  Partition(&head, 3);

  printer(head);
  return 0;
}

