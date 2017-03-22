/* Find if there is a path between one node and other
 * Basically we can use BFS or DFS to traverse the graph
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>

/* Defining the queue */
/* Each queue node  is a linked list node */
struct qNode {
  int data;
  struct qNode* next;
};

/* Defining the queue data structure */
struct Queue {
  struct qNode* head;
  struct qNode* tail;
};

/* Init a queue */
struct Queue* initQueue() {
  struct Queue* q = malloc(sizeof(struct Queue));
  q->head = NULL;
  q->tail = NULL;
  return q;
}

/* Insert an element into the queue */
void enque(struct Queue* q, int item) {
  struct qNode *newNode = malloc(sizeof(struct qNode));
  newNode->data = item;
  newNode->next = NULL;
  /* If it is the first element */
  if(q->head == NULL) {
    q->head = newNode;
    q->tail = newNode;
    return;
  }
  /* Otherwise just push it at the rear end */
  q->tail->next = newNode;
  q->tail = newNode;
}

/* Remove an element from the queue */
int deque(struct Queue* q) {
  if(q->head == NULL) {
    printf("Queue is empty\n");
    return 777;
  }
  int retVal = q->head->data;
  q->head = q->head->next; //Remove the first one in queue
  return retVal;
}

/*
 * Return if the queue is empty or not
 */
bool isQueueEmpty(struct Queue* q) {
  return(q->head == NULL);
}

/* Data structs to define a graph */
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
  bool *discovered;
};


/* Init the graph */
struct graph* graphInit(int num) {
  struct graph *g = malloc(sizeof(struct graph));
  int i =0;

  g->arrList = malloc(sizeof(struct listNode) * num);
  g->degree = malloc(sizeof(int) * num);
  g->num_nodes = num;

  //Discovered array for BFS
  g->discovered = malloc(sizeof(bool) * num);

  /* Init everyting */
  for(i=0; i<num; i++) {
    g->arrList[i].head = NULL;
    g->degree[i] = 0;
    g->discovered[i] = false;
  }
  /* Return this graph */
  return g;
}

/* init the search */
void initSearch(struct graph* g) {
  int num = g->num_nodes;
  int i = 0;
  for(i=0; i<num; i++)
    g->discovered[i] = false;
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


/*
 * Find if there is a path between the source
 * and destinitioni. The idea is, while traversing the graph
 * if we hit the node, the there should be a path between the
 * given nodes.
 */
bool isPath(struct graph* g, int src, int dest) {
  /*
   * For this we will need a queue. We visit the first node
   * shove it into a queue, and then visit all the neighbours.
   * We visit the neighbours only if they are undiscovered, and once
   * we discover them we add them to the queue and then keep dequeuing till
   * everything is discovered
   */
  struct Queue* q = initQueue();
  int u, v  = 0;

  /* Init the search to start with */
  initSearch(g);

  /* Enque the starting node */
  enque(q, src);

  while(!isQueueEmpty(q)) {
    u = deque(q); //Get the first element from the queue
    /* If we have found the node return TRUE */
    if(u == dest) return true;
    g->discovered[u] = true;
    /* Get a pointer to the head of the current edge */
    struct Node* curr = g->arrList[u].head;
    while(curr!=NULL) {
      v = curr->data;
      if(!g->discovered[v]) {
        g->discovered[v] = true;
        enque(q, v);
      }
      curr = curr->next;
    }
  }
  return false; //If we are here it means didn't find the node
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
  /* Find if there is a path on the graph between the given nodes */
  if(isPath(g, 1, 2))
      printf("There is a path\n");
  else
      printf("There is no path\n");

  if(isPath(g, 0, 3))
    printf("There is a path\n");
  else
    printf("There is no path\n");

  return 0;
}
