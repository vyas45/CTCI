/* Find if there is a loop in the list and return the node */
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
  printf("\n\n Printing the linked list\n\n");
  struct node* curr = head;
  while(curr->next != NULL) {
    printf("%d->", curr->data);
    curr = curr->next;
  }
  printf("%d\n", curr->data);
}

/* Get the looper node */
struct node* getLooper(struct node* head) {
  struct node* slow = head;
  struct node* fast = head;

  while(slow!=NULL && slow->next!=NULL) {
    fast = slow->next->next;
    if(slow == fast) {
      printf("Found the loop!!\n");
      return slow;
    }
    slow = slow->next;
  }
  /* Reached here means there was no loop */
  printf("There is no loop\n");
  return NULL;
}

int main() {
  struct node* head = NULL;
  struct node* looper = NULL;

  /*Insert a few nodes */
  InsertEnd(&head, 1);
  InsertEnd(&head, 2);
  InsertEnd(&head, 3);
  InsertEnd(&head, 4);

  /* Create the loop */
  head->next->next->next->next = head->next->next;

  /* Get the looper node */
  looper = getLooper(head);
  if(looper == NULL) {
    return 0;
  }
  printf("Loop is at %d\n", looper->data);

  /* Print list again */
  //printer(head);

  return 0;
}
