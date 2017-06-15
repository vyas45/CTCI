/*
 * Remove duplicate enteries from the linked list
 */
#include <stdio.h>
#include <stdlib.h>

/* linked list node */
struct node {
  int data;
  struct node* next;
};

/* Create a new node */
struct node* createNode(int val) {
  struct node* temp;
  temp = malloc(sizeof(struct node));
  if(temp == NULL)
    return NULL;
  temp->data = val;
  temp->next = NULL;
  return temp;
}

/* Insert a new Node at the end */
void InsertEnd(struct node** head, int val) {
  struct node* curr = NULL;
  if(*head == NULL) {
    *head =  createNode(val);
    return;
  }
  curr = *head; //Setup the iterator
  while(curr->next!=NULL) {
    curr = curr->next;
  }
  curr->next = createNode(val);
}

/* Remove duplicates from the linked list */
void RemoveDups(struct node* head) {
  struct node* first = head;
  struct node* second = head;

  while(first && first->next) {
    second = first;
    while(second && second->next) {
      //printf("%d and %d are same \n", second->data, second->next->data);
      if(first->data == second->next->data) {
        printf("%d and %d are same \n", second->data, second->next->data);
        second->next = second->next->next;
      }
      else
        second = second->next;
    }
    first =  first->next;
  }
}

/* Print the linked list */
void printer(struct node* head) {
  printf("\n\n Printing the linked list\n\n");
  struct node* curr = head;
  while(curr->next != NULL) {
    printf("%d->", curr->data);
    curr = curr->next;
  }
  printf("%d\n", curr->data);
}

int main() {
  struct node* head = NULL;

  /*Insert a few nodes */
  InsertEnd(&head, 1);
  InsertEnd(&head, 2);
  InsertEnd(&head, 1);
  InsertEnd(&head, 3);
  InsertEnd(&head, 2);

  /* Print List */
  printer(head);

  /* Remove duplicates */
  RemoveDups(head);

  /* Print list again */
  printer(head);

  return 0;
}
