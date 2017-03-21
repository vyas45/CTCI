/*
 * Implement a graph using the Adjacency List
 * Representation. For an array list representation 
 * an array of linked lists is used. Each node on the array
 * represets a node on the graph and all the links on it 
 * are represented as linked list nodes
 */
#include <stdio.h>
#include <stdlib.h>


struct Node {
  int data;
  struct Node* next;
};

struct listNode {
  struct Node* head;
};

struct graph {
  struct listNode* arrList;
  int* degree;
  int num_nodes;
};

/* Init the graph */
struct graph* graphInit(int num) {
  struct graph *g = malloc(sizeof(struct graph));
  int i =0; 

  g->arrList = malloc(sizeof(struct listNode) * num);
  g->degree = malloc(sizeof(int) * num);
  g->num_nodes = num;

  /* Init everyting */
  for(i=0; i<num; i++) {
    g->arrList[i].head = NULL;
    g->degree[i] = 0;
  }
  /* Return this graph */
  return g;
}

/* Create a new node of Node type */
struct Node* createNode(int item) {
  struct Node* temp = malloc(sizeof(struct Node));
  temp->data = item;
  temp->next = NULL;
  return temp;
}

/* Insert an edge in the graph */
void insertEdge(struct graph* g, int src, int dest) {
  struct Node* newNode = createNode(dest);

  /* Insert at the head and make curr the head */
  newNode->next  = g->arrList[src].head;
  g->arrList[src].head = newNode;
  g->degree[src]++;

  /* Need to add the reverse edge as well
   * Considering this as an undirected graph
   */
   newNode = createNode(src);
   newNode->next = g->arrList[dest].head;
   g->arrList[dest].head = newNode;
   g->degree[dest]++;
}

/* Remove an edge from the graph
 * Removing an edge from the graph involves a 2 way removal
 * because we are considering an undirected graph 
 */
void removeEdge(struct graph* g, int src, int dest) {
  /* First look into the src->dest and remove dest */
  struct Node* curr = g->arrList[src].head;

  /* If it is the head */
  if(curr->data == dest) {
    g->arrList[src].head = curr->next;
    g->degree[src]--;
  }
  while(curr->next!=NULL) {
    if(curr->next->data == dest) {
        curr->next = curr->next->next;
        g->degree[src]--;
    }
    curr = curr->next;
  }

  /* Also remove the dest->src edge */
  curr = g->arrList[dest].head;
  /* If it is the head */
  if(curr->data == src) {
    g->arrList[dest].head = curr->next;
    g->degree[dest]--;
  }
  while(curr->next!=NULL) {
    if(curr->next->data == src) {
        curr->next = curr->next->next;
        g->degree[dest]--;
    }
    curr = curr->next;
  }
}

/* Print the graph */
void Printer(struct graph* g) {
  int i = 0;

  for(i=0; i<g->num_nodes; i++) {
    printf("Printing info for node #%d\n", i);
    printf("Degree of the node is %d\n", g->degree[i]);
    struct Node* curr = g->arrList[i].head;
    while(curr!=NULL) {
        printf("%d-> ", curr->data);
        curr = curr->next;
    }
    printf("\n");
  }
}

int main() {
  struct graph *g = graphInit(3);

  insertEdge(g, 1, 2);
  insertEdge(g, 0, 2);
  insertEdge(g, 0, 1);

  Printer(g);

  removeEdge(g, 0, 1);
  removeEdge(g, 0, 2);

  printf("\n\n");
  Printer(g);

  return 0;
}
