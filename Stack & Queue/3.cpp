#include<bits/stdc++.h>
using namespace std;
// Stack implementation using Linked List
class Node{
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
class Stack {
public:
    Node*top = NULL;
    int size_t = 0;
    bool isEmpty() {
        return top == NULL;
    }
    void push(int x){
        Node* newNode = new Node(x);
        if (isEmpty()) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
        size_t++;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return ;
        } else {
            Node* temp = top;
            top = top->next;
            delete temp;
            size_t--;
        }
    }
    int Top() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        } else {
            return top->data;
        }
    }
    int size() {
        return size_t;
    }
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element is: " << s.Top() << endl;
    cout << "Stack size is: " << s.size() << endl;
    s.pop();
    cout << "Top element after pop is: " << s.Top() << endl;
    cout << "Stack size after pop is: " << s.size() << endl;
    return 0;
}