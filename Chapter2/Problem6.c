/*
 * Check if a linked List is a palindrome
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

/*
 * Recursively iterate the two lists to check if they are same
 */
void checkPalin(struct node *head1, struct node **head2) {
  if(head1 == NULL) return;
  else {
    checkPalin(head1->next, head2);
    printf("head 1 data is %d\n", head1->data);
    InsertEnd(head2, head1->data);
  }
}

/* 
 * Check if a linked list is a palindrom
 * The idea is that i find the mid of the linked list
 * and then reverse the second half of the linked list
 * and compare with first half
 */
void isPalindrome(struct node* head) {
  struct node* slow = head; //Slow pointer
  struct node* fast = head; //Fast pointer
  struct node* head2 = NULL; //Head to be passed on for the second half
  int len = 0; //Length of the linked list
  struct node* curr = head;
  struct node* newHead = NULL;//reversed list

  /* Get the lengh of the linked list */
  while(curr!=NULL) {
    len++;
    curr = curr->next;
  }

  /* Get the mid point depending on length being odd or even */
  while(fast->next!=NULL && fast->next->next!=NULL) {
      slow = slow->next;
      fast = fast->next->next;
  }
  head2 = slow->next;
  slow->next = NULL;

  checkPalin(head2, &newHead);

  while(newHead!=NULL) {
      if(head->data!=newHead->data) {
          printf("Not a palindrome\n");
          return;
      }
      head = head->next;
      newHead = newHead->next;
  }
  printf("It is a palindrome\n");
}

int main() {
  struct node* head = NULL;

  InsertEnd(&head, 1);
  InsertEnd(&head, 2);
  InsertEnd(&head, 3);
  InsertEnd(&head, 2);
  InsertEnd(&head, 1);

  printer(head);

  isPalindrome(head);

  return 0;
}
