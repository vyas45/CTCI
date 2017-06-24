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

/* Add two linked lists */
void addLists(struct node* h1, struct node* h2, struct node** h3) {
  if(h1 == NULL) {
    *h3 = h2;
    return;
  }
  else if(h2 == NULL) {
    *h3 = h1;
    return;
  }
  else {
    struct node* curr1 = h1;
    struct node* curr2 = h2;
    int sum, carry = 0;

    /* Iterate till one of the list ends */
    while(curr1 && curr2) {
      sum = curr1->data + curr2->data + carry;
      carry = sum/10;
      sum = sum%10;
      InsertEnd(h3, sum);
      curr1 = curr1->next;
      curr2 = curr2->next;
    }
    /* Second list ended */
    while(curr1) {
      printf("List 1 remains\n");
      sum = curr1->data + carry;
      carry = sum/10;
      sum = sum%10;
      InsertEnd(h3, sum);
      curr1 = curr1->next;
    }
    /* First list ended */
    while(curr2) {
      printf("List 2 2 remains\n");
      sum = curr2->data + carry;
      carry = sum/10;
      sum = sum%10;
      InsertEnd(h3, sum);
      curr2 = curr2->next;
    }
    /* Both ended but there is a carry */
    if(carry)
      InsertEnd(h3, carry);
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
  InsertEnd(&h1, 6);
  InsertEnd(&h1, 6);

  /* Second number */
  InsertEnd(&h2, 5);
  InsertEnd(&h2, 9);
  InsertEnd(&h2, 2);


  /* Print List */
  printer(h1);
  printer(h2);

  addLists(h1, h2, &h3);

  /* Print list again */
  printer(h3);

  return 0;
}
