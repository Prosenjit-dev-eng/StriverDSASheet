#include <stdio.h>
#include <stdlib.h>

// Node structure in C
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create new node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// -------- DFS TRAVERSALS ----------

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// -------- BFS LEVEL ORDER ----------

// Simple queue implementation for Node*
typedef struct {
    Node* arr[1000];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, Node* value) {
    if (q->rear == 999) return; // overflow safety
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = value;
}

Node* dequeue(Queue* q) {
    if (isEmpty(q)) return NULL;
    Node* temp = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

void levelOrder(Node* root) {
    if (!root) return;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        Node* curr = dequeue(&q);
        printf("%d ", curr->data);

        if (curr->left) enqueue(&q, curr->left);
        if (curr->right) enqueue(&q, curr->right);
    }
}

// -------- MAIN FUNCTION ----------

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->left->left = createNode(3);
    root->right = createNode(7);
    root->left->right = createNode(4);
    root->left->right->left = createNode(5);
    root->left->right->right = createNode(6);

    inorder(root);     printf("\n");
    preorder(root);    printf("\n");
    postorder(root);   printf("\n");
    levelOrder(root);  printf("\n");

    return 0;
}
