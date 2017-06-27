/*
 * Merge two linked lists together
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

/* Merge the two lists */
void Merge(struct node** h1, struct node* h2) {
  struct node* prev = *h1;
  struct node* ph1 = *h1;
  struct node* ph2 = h2;

  if(*h1 == NULL && h2 == NULL) return NULL;
  else if(h2 == NULL)  return (*h1);
  else if(h1 == NULL) return (h1);
  else {
    if(h1->data<=h2->data) {
      prev = h1;
      h1 = h1->next;
    }
    else {
      struct node* temp = prev;
      prev->next = 
    }



  }

}

int main() {
  struct node* h1 = NULL;
  struct node* h2 = NULL;

  /*Insert a few nodes */
  InsertEnd(&h1, 1);
  InsertEnd(&h1, 4);
  InsertEnd(&h1, 5);

  InsertEnd(&h2, 2);
  InsertEnd(&h2, 6);

  /* Print List */
  printer(h1);
  printer(h2);

  /* Merge the two lists */
  MergeLists(&h1, h2);

  return 0;
}
