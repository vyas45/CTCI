/*
 * Find a route between the two nodes
 */

struct node {
    int data;
    struct node* next;
};

struct edgeList {
    struct node* headNode;
};

struct graph {
    struct edgeList* arr;
    int v;
    bool *discovered;
};

/*
 * DFS implemenetaiton
 */
bool DFS(struct graph* g, int start, int end) {
    if(g == NULL) return false;
    else {
        if(start == end) return true;
        struct node* curr = g->arr[start].headNode;
        while(curr!=NULL) {
            if(!g->discoverted[curr->data]) {
                g->discovered[curr->data] = true;
                DFS(g, curr->data, end);
            }
            curr = curr->next;
        }
    }
    return false; //If we reached here didn't find the node
}

/* 
 * BFS implementation 
 */
bool BFS(struct graph* g, int start, int end) {
    if(g == NULL) return false;
    else {
        struct queue* q = qInit();
        int u, v = 0;
        enque(q, start);
        while(!isEmpty(q)) {
            u = deque();
            if(u == end) return true;
            g->discovered[u] = true;
            struct node* curr = g->edgeList[u].headNode;
            while(curr!=NULL) {
                v = curr->data;
                if(!g->discovered[v]) {
                    g->discovered[v] = true;
                    enque(q, v);
                }
                curr = curr->next;
            }
        }
    }
    return false; //If we reach here didn't find it
}
