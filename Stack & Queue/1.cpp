#include<bits/stdc++.h>
using namespace std;
// Stack implementation using array
#define MAX 1000
class Stack {
    int top;
    int arr[MAX];
public:
    Stack() { top = -1; }
    
    bool isEmpty() {
        return (top < 0);
    }
    
    bool push(int x) {
        if (top >= (MAX - 1)) {
            cout << "Stack Overflow\n";
            return false;
        } else {
            arr[++top] = x;
            cout << x << " pushed to stack\n";
            return true;
        }
    }
    
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        } else {
            return arr[top--];
        }
    }
    
    int Top() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        } else {
            return arr[top];
        }
    }
    int size() {
        return top + 1;
    }
};
int main()
{
    Stack s;
    s.push(3);
  s.push(7);
  cout << "Top of stack is before deleting any element " << s.Top() << endl;
  cout << "Size of stack before deleting any element " << s.size() << endl;
  cout << "The element deleted is " << s.pop() << endl;
  cout << "Size of stack after deleting an element " << s.size() << endl;
  cout << "Top of stack after deleting an element " << s.Top() << endl;
    return 0;
}