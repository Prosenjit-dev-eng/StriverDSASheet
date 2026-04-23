#include<bits/stdc++.h>
using namespace std;
// Queue implementation using array
#define MAX 1000
class Queue {
    int front, rear,currsize;
    int arr[MAX];
public:
    Queue() { front = -1; rear = -1,currsize = 0; }
    int push(int x) {
        if (currsize == MAX) {
            cout << "Queue is full\n";
            return -1;
        }
        if(currsize == 0) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        arr[rear] = x;
        currsize++;
        return 0;
    }
    int pop() {
        if (currsize == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        // Here we are destroying the queue
        // So we put the element at start
        int ele = arr[front];
        if(currsize == 1){
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX;
        }
        currsize--;
        return ele;
    }
    int top() {
        if (currsize == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
    int size() {
        return currsize;
    }
};
int main()
{
  Queue q;
  q.push(4);
  q.push(14);
  q.push(24);
  q.push(34);
  cout << "The peek of the queue before deleting any element " << q.top() << endl;
  cout << "The size of the queue before deletion " << q.size() << endl;
  cout << "The first element to be deleted " << q.pop() << endl;
  cout << "The peek of the queue after deleting an element " << q.top() << endl;
  cout << "The size of the queue after deleting an element " << q.size() << endl;

    return 0;
}