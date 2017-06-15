/*
 * Delete the given node somewhere in between
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Define the node structure
 */
struct node {
  int data;
  struct node* next;
};

/* Method to create a new Node */
struct node* createNode(int item) {
  struct node* newNode = malloc(sizeof(struct node));
  /* If the allocation fails */
  if(newNode == NULL) {
    printf("Couldn't allocate a newNode\n");
    return NULL;
  }
  newNode->data = item;
  newNode->next = NULL;
  return newNode;
}

/* Insert a new Node at the end */
void InsertEnd(struct node** head, int item) {
  struct node* temp = NULL;

  /* Create a new node with the data */
  temp = createNode(item);
  if(temp == NULL) {
    return; //Not able to create a node
  }

  /* Check if we are the first node */
  if(*head == NULL) {
    *head = temp;
    return;
  }

  /* Get an iterator */
  struct node* curr  = *head;
  /* Iterate to the end of the linked list */
  while(curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = temp; //Push the new Node at the end
}

/* Delete a middle node */
void DelMid(struct node* node){
  node->data = node->next->data;
  node->next = node->next->next;
}

/* Print the linked list */
void printer(struct node* head) {
  printf("\nPrinting the linked list\n");
  struct node* curr = head;
  while(curr->next != NULL) {
    printf("%d->", curr->data); 
    curr = curr->next;
  }
  printf("%d\n\n", curr->data);
}

int main() {
  struct node* head = NULL;

 /*Insert a few more at the end */
  InsertEnd(&head, 1);
  InsertEnd(&head, 2);
  InsertEnd(&head, 3);
  InsertEnd(&head, 4);

  /*Print the linked List */
  printer(head);

  /* Delete Middle */
  DelMid(head->next->next);

  printer(head);

  return 0;
}
