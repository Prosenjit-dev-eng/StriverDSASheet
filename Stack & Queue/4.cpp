#include<bits/stdc++.h>
using namespace std;
// Queue implementation using linked list
class Node {
    public:
    int data;
    Node*next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class Queue{
    public:
    Node*start = NULL;
    Node*end = NULL;
    int currsize = 0;
    void push(int x) {
        Node*newNode = new Node(x);
        if (currsize == 0) {
            start = end = newNode;
        } else {
            end->next = newNode;
            end = newNode;
        }
        currsize++;
    }
    int pop() {
        if (currsize == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        int ele = start->data;
        Node*temp = start;
        start = start->next;
        delete temp;
        currsize--;
        if (currsize == 0) {
            end = NULL; // If queue becomes empty, reset end
        }
        return ele;
    }
    int top() {
        if (currsize == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return start->data;
    }
    int size() {
        return currsize;
    }
};
int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Front element is: " << q.top() << endl;
    cout << "Queue size is: " << q.size() << endl;
    q.pop();
    cout << "Front element after pop is: " << q.top() << endl;
    cout << "Queue size after pop is: " << q.size() << endl;
    return 0;
}