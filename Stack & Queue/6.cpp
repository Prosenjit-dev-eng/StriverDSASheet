#include<bits/stdc++.h>
using namespace std;
// Queue implementation using stack
class QueueUsingStack {
    public:
    stack<int> s1, s2;
    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    void pop() {
        if (s1.empty()) {
            cout << "Queue is empty\n";
            return;
        }
        s1.pop();
    }
    int Top() {
        if (s1.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return s1.top();
    }
    int size() {
        return s1.size();
    }
    bool isEmpty() {
        return s1.empty();
    }
};
int main()
{
    QueueUsingStack q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "Front element is: " << q.Top() << endl;
    cout << "Queue size is: " << q.size() << endl;
    q.pop();
    cout << "Front element after pop is: " << q.Top() << endl;
    cout << "Queue size after pop is: " << q.size() << endl;
    return 0;
}