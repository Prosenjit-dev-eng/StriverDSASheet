#include <stdio.h>
#include <stdlib.h>

int cnt = 0;

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Insert at END (not at front)
void addEdge(Node* adj[], int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;

    if (adj[u] == NULL) {
        adj[u] = newNode;
    } else {
        Node* temp = adj[u];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void dfsUtil(int start, int vis[], Node* adj[], int result[], int *idx) {
    vis[start] = 1;
    result[(*idx)++] = start;

    Node* temp = adj[start];
    while (temp != NULL) {
        int v = temp->vertex;
        if (!vis[v]) {
            cnt++;
            printf("%d\n", cnt);
            dfsUtil(v, vis, adj, result, idx);
        }
        temp = temp->next;
    }
}

void dfsGraph(int V, Node* adj[], int result[], int *idx) {
    int vis[V];
    for (int i = 0; i < V; i++)
        vis[i] = 0;

    dfsUtil(0, vis, adj, result, idx);
}

int main() {
    int V = 8;
    Node* adj[V];

    for (int i = 0; i < V; i++)
        adj[i] = NULL;

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

    int result[100];
    int idx = 0;

    dfsGraph(V, adj, result, &idx);

    printf("DFS Traversal: ");
    for (int i = 0; i < idx; i++)
        printf("%d ", result[i]);

    return 0;
}
