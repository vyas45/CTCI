/*
 * Determine if the two linked lists intersect
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node {
  int data;
  struct node* next;
};

/*
 * Create a new node and return it back
 */
struct node* createNode(int item) {
  struct node* temp = malloc(sizeof(struct node));
  if(temp == NULL) {
    printf("Couldn't allocate a node\n");
    return NULL;
  }
  temp->data = item;
  temp->next = NULL;
  return temp;
}

/*
 * Push a new node into the linked list
 */
void PushEnd(struct node** head, int item) {
  struct node* temp = createNode(item);
  if(temp == NULL) return; 

  if(*head == NULL) {
    *head = temp;
    return;
  }
  struct  node* curr = *head;
  while(curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = temp;
}

bool Intersect(struct node* head1, struct node* head2) {
  if(head1 == NULL || head2 == NULL) return false;
  else {
    if(head1 == head2) return true;
    return (Intersect(head1->next, head2->next));
  }
}

bool isIntersecting(struct node* head1, struct node* head2) {
  int len1 = 0;
  int len2 = 0;
  int i = 0;

  struct node* curr1 = head1;
  struct node* curr2 = head2;

  /* Compute the length of first list */
  while(curr1) {
    len1++;
    curr1 = curr1->next;
  }

  /* Compute the length of second list */
  while(curr2) {
    len2++;
    curr2 = curr2->next;
  }

  curr1 = head1;
  curr2 = head2;

  if(len1 == len2)
    return(Intersect(curr1, curr2));
  else if(len1>len2) {
    for(i=0; i<(len1-len2); i++) {
      curr1 = curr1->next;
    }
    return (Intersect(curr1, curr2));
  }
  else {
    for(i=0; i<(len2-len1); i++) {
      curr2 = curr2->next;
    }
    return (Intersect(curr1, curr2));
  }
}

/* Printer */
void printer(struct node* head) {
  printf("\n");
  struct node* curr = head;
  while(curr->next != NULL) {
    printf("%d->", curr->data);
    curr = curr->next;
  }
  printf("%d\n", curr->data);
}

int main() {
  struct node* head1 = NULL;
  struct node* head2 = NULL;

  PushEnd(&head1, 1);
  PushEnd(&head1, 2);
  PushEnd(&head1, 3);
  PushEnd(&head1, 4);
  PushEnd(&head1, 5);

  /* Create head2 */
  PushEnd(&head2, 7);
  PushEnd(&head2, 8);

 // head2->next->next = head1;


  printer(head1);

  printf("Second linked list is \n");

  printer(head2);

  if(isIntersecting(head1, head2))
    printf("They intersect!\n");
  else
    printf("They do not intersect\n");

  return 0;
}
