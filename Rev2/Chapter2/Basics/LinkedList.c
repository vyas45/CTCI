/*
 * Implement some basic linked list routines
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

/* Insert a new Node at the front */
void InsertFront(struct node** head, int item) {
  struct node* temp = NULL;

  /* Create a new Node with the data */
  temp = createNode(item);
  if(temp == NULL) {
    return;
  }
  /* If we are the first node */
  if(*head == NULL) {
    *head = temp;
    return;
  }
  /* Otherwise we shove the node at the front */
  temp->next = *head;
  *head = temp; //Make the newNode the head
}

/* Delete a given node in the linked list */
void DeleteNode(struct node** head, int item) {
  struct node* curr = NULL;
  bool found = false;

  /* If the linked list is empty return */
  if(*head == NULL) {
    printf("List empty, nothing to delete\n");
    return;
  }
  /* If the head node is to be deleted
   * pointers need to be deleted appropriately
   */
  if((*head)->data == item) {
    found = true;
    *head = curr->next;
    free(curr);
  }
  /* Start at the head */
  curr = *head;
  while(curr!=NULL && curr->next!=NULL) {
    if(curr->next->data == item) {
      found = true;
      printf("Found %d and deleting\n", curr->next->data);
      curr->next = curr->next->next;
      free(curr->next);
    }
    curr = curr->next;
  }
  if(!found) 
    printf("Element %d not found in the linked list\n", item);
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

  /*Insert a fewNodes at the front */
  InsertFront(&head, 1);
  InsertFront(&head, 2);
  InsertFront(&head, 3);
  InsertFront(&head, 4);

  /*Print the linked List */
  printer(head);

  /*Insert a few more at the end */
  InsertEnd(&head, 5);
  InsertEnd(&head, 6);
  InsertEnd(&head, 7);
  InsertEnd(&head, 8);

  /*Print the linked List */
  printer(head);

  /*Delete nodes */
  DeleteNode(&head, 3);
  printer(head);

  DeleteNode(&head, 8);
  printer(head);

  /*Delete the head */
  DeleteNode(&head, 8);
  printer(head);

  return 0;
}
