/* Add two linked lists representing numbers */
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

/* Insert a new node in front of the list */
void InsertFront(struct node** head, int val) {
  struct node* temp = createNode(val);
  /* If it is the first node */
  if(*head == NULL) {
    *head = temp;
    return;
  }
  /* Subsequent inserts */
  temp->next = *head;
  *head = temp;
}

/* Print the linked list */
void printer(struct node* head) {
  if(head == NULL) {
    printf("\n\nEmpty Linked List \n");
    return;
  }
  printf("\n\n Printing the linked list\n\n");
  struct node* curr = head;
  while(curr->next != NULL) {
    printf("%d->", curr->data);
    curr = curr->next;
  }
  printf("%d\n", curr->data);
}

/* Add two lists */
void addLists(struct node* h1, struct node* h2, struct node** h3) {
  int sum, carry = 0;
  if(h1 == NULL && h2 == NULL) return;
  else {
    printf("carry is %d\n", carry);
    addLists(h1->next, h2->next, h3);
    sum = h1->data  + h2->data;
    carry = sum/10;
    sum =  sum%10;
    InsertFront(h3, sum);
  }
}

int main() {
  struct node* h1 = NULL;
  struct node* h2 = NULL;
  struct node* h3 = NULL;

  /* First number */
  InsertEnd(&h1, 7);
  InsertEnd(&h1, 1);
  InsertEnd(&h1, 6);

  /* Second number */
  InsertEnd(&h2, 1);
  InsertEnd(&h2, 1);
  InsertEnd(&h2, 1);


  /* Print List */
  printer(h1);
  printer(h2);

  addLists(h1, h2, &h3);

  /* Print list again */
  printer(h3);

  return 0;
}
