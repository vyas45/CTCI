/*
 * Get the kth from the last element form the end
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

struct node* createNode(int item) {
  struct node* temp;
  temp = malloc(sizeof(struct node));
  if(temp == NULL)
    return temp;
  temp->data = item;
  temp->next = NULL;
  return temp;
}

/* Insert the nodes in the list */
void InsertNode(struct node** head, int item) {
  struct node* curr = NULL;
  if(*head == NULL) {
    *head  = createNode(item);
    return;
  }
  curr = *head;
  while(curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = createNode(item);
}

/* getKthNode() -> Gets the kth node from the end */
void getKthNode(struct node* head, int k) {
  int i = 0;
  struct node* prev = head;
  struct node* curr = head;

  for(i=0; i<k; i++) {
    if(curr==NULL) {
      printf("Out of bounds!!\n");
      return;
    }
    curr =  curr->next;
  }

  while(curr && prev) {
    curr = curr->next;
    prev = prev->next;
  }
  printf("The %dth element from the end is %d\n", k, prev->data);
}

/* Print the list */
void printer(struct node* head) {
  struct node* curr = head;
  while(curr!=NULL) {
    printf("%d-> ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

int main() {
  struct node* head = NULL;

  /* Insert Nodes */
  InsertNode(&head, 1);
  InsertNode(&head, 2);
  InsertNode(&head, 3);
  InsertNode(&head, 4);
  InsertNode(&head, 5);

  /* Print the list */
  printer(head);

  /* Get Kth Node */
  int k;
  getKthNode(head, 1);
  getKthNode(head, 2);
  getKthNode(head, 13);

  return 0;
}
