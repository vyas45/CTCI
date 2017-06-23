/*
 * Check if a linked list is palindrome
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Define the structure of a node */
struct node {
  int data;
  struct node* next;
};

/* Creating a new Node */
struct node* createNode(int item) {
  struct node* temp = malloc(sizeof(struct node));
  if(temp == NULL)  {
    printf("Couldn't allocate a node\n");
    return NULL;
  }
  temp->data = item;
  temp->next = NULL;
  return temp;
}

/* Insert a new node at the end */
void insertEnd(struct node** head, int item) {
  struct node* temp = createNode(item);
  /* First node in the list */
  if(*head == NULL) {
    *head = temp;
    return;
  }
  /* Iterate through and insert at the end */
  struct node* curr = *head;
  while(curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = temp;
}

/* Print the list */
void printer(struct node* head) {
  struct node* curr = head;
  while(curr->next != NULL) {
    printf("%d->", curr->data);
    curr = curr->next;
  }
  printf("%d\n", curr->data);
}

/* Insert a new node at the front */
void insertFront(struct node** head, int item) {
  struct node* temp = createNode(item);
  /* First node in the list */
  if(*head == NULL) {
    *head = temp;
    return;
  }
  /* Make the new Node the head */
  temp->next = *head;
  *head = temp;
}

/* Reverse the linked list */
struct node* reverseList(struct node* head) {
  struct node* retList = NULL;
  struct node* curr = head;
  /* Keep pushing in front as we iterate through */
  while(curr != NULL) {
    insertFront(&retList, curr->data); 
    curr = curr->next;
  }
  /* Return back the reversed list */
  return retList;
}

/* Check if a linked list is a palindrome */
bool isPalin(struct node* head) {
  struct node* curr1 = head;
  /* Reverse the list */
  struct node* curr2 = reverseList(curr1);

  printf("The reversed list is \n");
  printer(curr2);

  while(curr1 != NULL) {
    if(curr1->data != curr2->data) return false;
    curr1 = curr1->next;
    curr2 = curr2->next;
  }
  /* Reached here must be fine */
  return true;
}

int main() {
  struct node* head = NULL;

  insertEnd(&head, 1);
  insertEnd(&head, 2);
  insertEnd(&head, 3);
  insertEnd(&head, 2);
  insertEnd(&head, 1);

  printer(head);

  if(isPalin(head))
    printf("The list is a plaindrome\n");
  else
    printf("The list is not a palindrome\n");

  return 0;
}
