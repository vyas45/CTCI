/*
 *  Delete all nodes with value = k
 */
#include <stdio.h>
#include <stdlib.h>

/* Define the node structure */
struct node {
  int data;
  struct node* next;
};

/* Create a new node */
struct node* createNode(int item) {
  struct node* temp = malloc(sizeof(struct node));
  if(temp == NULL) return NULL;
  temp->data = item;
  temp->next = NULL;
  return temp;
}

/* Insert a node at the end of linked list */
void InsertEnd(struct node** head, int item) {
  struct node* temp = createNode(item);
  /* First node in the linked list */
  if(*head == NULL) {
    *head = temp;
    return;
  }
  struct node* curr = *head;
  while(curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = temp;
}

/* Printer */
void printer(struct node* head) {
  printf("\n***** Printing the list *****\n");
  struct node* curr = head;
  while(curr->next != NULL) {
    printf("%d->", curr->data);
    curr = curr->next;
  }
  printf("%d\n", curr->data);
}

/* Delete node with value = k */
void deleteKs(struct node** head, int key) {
  if(*head == NULL) return;

  struct node* slow = *head;
  struct node* fast = *head;

  /* Take care of header nodes */
  while(slow != NULL && slow->data == key) {
    slow = slow->next;
  }
  if(slow == NULL) return;
  *head = slow; //Update the head

  while(slow!=NULL && slow->next!=NULL) {
    fast = slow->next;
    while(fast != NULL && fast->data == key) {
      fast = fast->next;
    }
    slow->next = fast;
    slow = fast;
  }
}

int main() {
 struct node* head = NULL;

 /* Insert Nodes */
 InsertEnd(&head, 1);
 InsertEnd(&head, 2);
 InsertEnd(&head, 3);
 InsertEnd(&head, 2);
 InsertEnd(&head, 2);

 /* Print the linked list */
 printer(head);

 /* Delete nodes with value == k */
 deleteKs(&head, 2);

 /* print the new linked list */
 printer(head);

 return 0;
}

