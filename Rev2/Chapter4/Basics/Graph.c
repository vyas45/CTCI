/*
 * Basic graph adjacency list implementation
 * Primitives implememnted are:
 * 1. InsertEdge()
 * 2. RemoveEdge()
 * 3. IsEdge()
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Each node on the adjacency list */
struct node {
    int data;
    struct node* next;
};

/* Maintaining a list heads of vertices */
struct adjList {
    struct node* head;
};

/* Graph structure */
struct graph {
    int v;
    struct adjList* arr;
    int *degree; //degree of every node
};

/* Create a new node */
struct node* createNode(int item) {
    struct node* newNode = malloc(sizeof(struct node));
    if(newNode == NULL) {
        printf("Couldn't allocate node\n");
        return newNode;
    }
    newNode->data = item;
    newNode->next = NULL;
    return newNode;
}

/* Init the graph */
struct graph* initGraph(int size) {
    struct graph* g = (struct graph*)malloc(sizeof(struct graph));
    g->v = size;
    g->arr = (struct adjList*)malloc(sizeof(struct adjList) * size);
    g->degree = malloc(sizeof(int) * size);
   
    /* Inits */ 
    int i = 0;
    for(i = 0; i<size; i++) {
        g->arr[i].head = NULL;
        g->degree[i] = 0;
    }

    return g;
}

/* Insert an edge from the graph */
void InsertEdge(struct graph* g, int src, int dest) {
    /* We need to insert an edge from src to dest
     * and dest to src as well(considering an undirected
     * graph
     */
    struct node* newNode = createNode(dest);

    /* Insert the edge from src to head */
    newNode->next = g->arr[src].head;
    g->arr[src].head = newNode;
    g->degree[src]++;

    /* Now insert other way */
    newNode = createNode(src);
    newNode->next = g->arr[dest].head;
    g->arr[dest].head = newNode;
    g->degree[dest]++;

}

/* Remove edge from the graph */
void RemoveEdge(struct graph* g, int src, int dest) {
    /* We need to remove edge from both dest to src
     * and src to dest(undirected graph)
     */
    /* No nodes exist */
    if(g->degree[src] == 0) {
        printf("There is no edge\n");
        return;
    }
    /* Remove the edge from src->dest */
    struct node* curr = g->arr[src].head;

    /* If the head node is to be deleted */
    if(curr->data == dest) {
        g->arr[src].head = curr->next;
        free(curr);
    }
    else {
        while(curr->next!=NULL && curr->next->data!=dest) {
            curr = curr->next;
        }
        /* Edge doesn't exist */
        if(curr->next == NULL) {
            printf("Edge doesn't exist\n");
            return;
        }
        curr->next = curr->next->next;
        free(curr->next);
    }

    /* Get rid of dest->src edge */
    curr = g->arr[dest].head;

    /* If the head node is to be deleted */
    if(curr->data == src) {
        g->arr[dest].head = curr->next;
        free(curr);
        return;
    }
    else {
        while(curr->next!=NULL && curr->next->data!=src) {
            curr = curr->next;
        }
        curr->next = curr->next->next;
        free(curr->next);
    }
}

/* Print the graph */
void Printer(struct graph* g) {
  int i = 0;

  for(i=0; i<g->v; i++) {
    printf("Printing info for node #%d\n", i);
    printf("Degree of the node is %d\n", g->degree[i]);
    struct node* curr = g->arr[i].head;
    while(curr!=NULL) {
        printf("%d-> ", curr->data);
        curr = curr->next;
    }
    printf("\n");
  }
}

int main() {
  struct graph *g = initGraph(3);

  InsertEdge(g, 1, 2);
  InsertEdge(g, 0, 2);
  InsertEdge(g, 0, 1);

  Printer(g);

  RemoveEdge(g, 0, 1);
  RemoveEdge(g, 0, 2);

  printf("\n\n");

  return 0;
}
