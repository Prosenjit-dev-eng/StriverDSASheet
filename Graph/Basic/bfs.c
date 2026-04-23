#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// ---------------- QUEUE USING LINKED LIST ----------------

typedef struct QNode {
    int data;
    struct QNode* next;
} QNode;

typedef struct Queue {
    QNode* front;
    QNode* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int val) {
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    temp->data = val;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(Queue* q) {
    if (q->front == NULL)
        return -1;

    int val = q->front->data;
    QNode* temp = q->front;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return val;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

// ---------------- GRAPH (Adjacency List) ------------------

void addEdge(Node* adj[], int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;

    if (adj[u] == NULL)
        adj[u] = newNode;
    else {
        Node* temp = adj[u];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// ---------------------- BFS -------------------------------

void bfs(int V, Node* adj[], int result[], int* idx) {
    int vis[V];
    for (int i = 0; i < V; i++) vis[i] = 0;

    Queue* q = createQueue();

    enqueue(q, 0);
    vis[0] = 1;

    while (!isEmpty(q)) {
        int node = dequeue(q);
        result[(*idx)++] = node;

        Node* temp = adj[node];
        while (temp != NULL) {
            int v = temp->vertex;
            if (!vis[v]) {
                vis[v] = 1;
                enqueue(q, v);
            }
            temp = temp->next;
        }
    }
}

// ---------------------- MAIN ------------------------------

int main() {
    int V = 8;
    Node* adj[V];
    for (int i = 0; i < V; i++) adj[i] = NULL;

    // UNDIRECTED GRAPH (add both ways)
    addEdge(adj, 0, 1); addEdge(adj, 1, 0);
    addEdge(adj, 0, 2); addEdge(adj, 2, 0);
    addEdge(adj, 1, 3); addEdge(adj, 3, 1);
    addEdge(adj, 1, 4); addEdge(adj, 4, 1);
    addEdge(adj, 2, 5); addEdge(adj, 5, 2);
    addEdge(adj, 2, 6); addEdge(adj, 6, 2);
    addEdge(adj, 3, 7); addEdge(adj, 7, 3);
    addEdge(adj, 4, 7); addEdge(adj, 7, 4);
    addEdge(adj, 5, 7); addEdge(adj, 7, 5);
    addEdge(adj, 6, 7); addEdge(adj, 7, 6);

    int result[100], idx = 0;

    bfs(V, adj, result, &idx);

    printf("BFS Traversal: ");
    for (int i = 0; i < idx; i++)
        printf("%d ", result[i]);

    return 0;
}
