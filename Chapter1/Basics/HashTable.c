/* Implement a basic hash table */
#include <stdio.h>
#include <stdlib.h>

/* Define a node to store data in HashTable */
struct node {
    int data;
    struct node *next;
};

/* The Hash Table */
struct hash {
    struct node* arr; //Array of "node" type
    int *num_coll; //Number of collisions
    int size; //Size of hashtable
};

/* Init the hash table */
struct hash* initHash(struct hash** h, int size) {
  int i = 0;
  *h = malloc(sizeof(struct hash));
  *h->arr = malloc(sizeof(struct node) * size);
  *h->num_coll = malloc(sizeof(int) * size);
  *h->size =size;
  
  /* Init all the head pointers */
  for(i=0; i<size; i++) {
   *h->arr[i] = NULL;
   *h->num_coll = -1; //Start with -1 and increment it unconditionally
  }
}

/* Create a new node of type "node" */
struct node* createNode(int item) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = item;
  newNode->next = NULL;
  return newNode;
}

/* Compute the hash for the integer */
int computeHash(struct hash *h, int item) {
  return( item % h->size);
}

/* Insert entry into the hash */
void Insert(struct hash** h, int item) {
    if(*h == NULL) return;

    struct node* newNode =  createNode(item); //Create a new Node
    int hash = computeHash(*h, item); //Compute the has to insert at the right position

    newNode->next = *h->arr[hash]; //Point it to the head
    *h->arr[hash] = newNode; //Make it the head
    *h->num_coll++; //Increment the number of colissions
}

/* Printer for the hash table */
void Printer(struct hash* h) {
  struct node* curr = NULL;
  int i = 0;

  for(i=0; i<h->size; i++) {
    printf("Printing the hashTable for node #%d\n\n", i);
    curr = h->arr[i];
    while(curr!=NULL) {
      printf("%d--> ", curr->data);
      curr =  curr->next;
    }
    printf("\n\n");
  }
}

int main() {
  struct hash* h = NULL;

  initHash(&h, 5);

  Insert(&h, 1 );
  Insert(&h, 2 );
  Insert(&h, 3 );

  //Remove();

  Printer(h);

  return 0;
}
