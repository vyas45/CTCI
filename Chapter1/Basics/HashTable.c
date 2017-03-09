/* Implement the basic Hash Table Routines */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Define a basic node */
struct hnode {
  int data;
  struct hnode* next;
};

/* Define the head of the array */
struct headList {
  struct hnode* hList;
};

/* Define the hash table */
struct hash {
  struct headList* arr; //Array of heads
  int* num_coll; //Number of collisions
  int size; //Size of hash table
};


/* Init the hash table */
struct hash* hInit(int size) {
  struct hash* h = NULL;
  int i = 0;

  h = malloc(sizeof(struct hash));
  h->arr = malloc(sizeof(struct headList) * size); //Array of ptrs
  h->num_coll = malloc(sizeof(int) * size);
  h->size  = size;

  for(i=0; i<size; i++) {
    h->arr[i].hList = NULL;
    h->num_coll[i] = -1;//We start with -1 to "always" increment
  }

  return h; //Return the hash table object
}

/* Create a new Node */
struct hnode* createNode(int item) {
  struct hnode* newNode = NULL;

  newNode = malloc(sizeof(struct hnode));
  newNode->data = item;
  newNode->next = NULL;

  return newNode;
}

/* Compute Hash */
int computeHash(struct hash* h, int item) {
  return( item % (h->size));
}

/* Insert an element into the hash table */
void Insert(struct hash* h, int item) {
  if(h==NULL) return;
  struct hnode* newNode = createNode(item);
  int hash  = 0;

  /* Compute the hash for the input */
  hash = computeHash(h, item);

  /* Insert at the head-end of the appropriate head */
  newNode->next = h->arr[hash].hList;
  h->arr[hash].hList = newNode;
  h->num_coll[hash]++;
}

/* Delete element from the hash table */
void Delete(struct hash* h, int item) {
  struct hnode* curr = NULL;
  int hash = computeHash(h, item);
  bool flag = false; //Keep a flag to check if we found an element

  curr = h->arr[hash].hList;

  /*
   * If the element is at the head
   * need to remove it and update the head
   */
   if(curr->data == item) {
     flag = true;
      h->arr[hash].hList = curr->next;
      free(curr);
   }
   while(curr->next!=NULL) {
    if(curr->next->data == item) {
      flag = true;
      struct hnode* temp = curr->next;
      curr->next = curr->next->next;
      free(temp);
    }
    curr = curr->next;
   }

   if(!flag)
     printf("Element not found to delete!!\n");
}

/* Printer for the HashTable */
void Printer(struct hash* h) {
  printf("Printing the hash table\n\n");
  if(h == NULL) return;
  struct hnode* curr = NULL;
  int i = 0;

  for(i=0; i<h->size; i++) {
    printf("Printing the entry for index %d\n", i);
    curr = h->arr[i].hList;
    while(curr!=NULL) {
      printf("%d--> ", curr->data);
      curr = curr->next;
    }
    printf("\n\n");
  }
}

int main() {
  struct hash* h = NULL;

  h = hInit(5);

  /* Insert Data into Hash Table */
  Insert(h, 1);
  Insert(h, 2);
  Insert(h, 3);
  Insert(h, 6);
  Insert(h, 5);
  Insert(h, 12);

  Printer(h);

  /* Delete from the hash Table */
  Delete(h, 12);

  Printer(h);

  return 0;
}
