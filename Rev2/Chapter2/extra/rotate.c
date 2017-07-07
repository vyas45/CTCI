/* Rotate a linked list by value k
 *
 * 1->2->3->4->5->NULL, if k = 2
 *
 * Result -> 4->5->1->2->3->NULL
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
  if(curr == NULL) {
    printf("The list is empty\n");
    return;
  }
  while(curr->next != NULL) {
    printf("%d->", curr->data);
    curr = curr->next;
  }
  printf("%d\n", curr->data);
}

/* Rotate the linked list by k units */
struct node* rotateK(struct node* head, int k) {
  int i = 0;
  struct node* slow = head;
  struct node* fast = head;
  int len =  0; //length of the linked list 
  struct node* temp;

  while(slow) {
    len++;
    slow = slow->next;
  }
  printf("Length is %d\n", len);
  slow = head; //make it head again
  /* If there is only one node or nothing to rotate or rotations equal the length */
  if(slow->next == NULL || k==0 || len == k)
    return slow;
/*
  for(i=0; i<k; i++) {
    printf("Data is %d\n", fast->data);
    if(fast == NULL) {
      fast = head;
    }
    else {
      fast = fast->next;
    }
  }
  while(fast->next && slow) {
    fast = fast->next;
    slow = slow->next;
  }
  temp = slow->next;
  slow->next = NULL;
  fast->next = head;
  head = temp;

  return head;
}

int main() {
  struct node* head = NULL;

  /* Insert Nodes */
  InsertEnd(&head, 1);
  InsertEnd(&head, 2);

  /* Print the linked list */
  printer(head);

  /* Rotate the list by k */
  struct node* rHead = NULL;
  rHead = rotateK(head, 4);

  /* print the new linked list */
  printer(rHead);

  return 0;
}

