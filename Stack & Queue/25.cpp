#include<bits/stdc++.h>
using namespace std;
class MinStack {
    stack<int>st;
    int mini;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if (st.empty())
        {
            mini = value;
            st.push(value);
        }
        if(mini < value)  st.push(value);
        else{
            st.push(2*value - mini);
            mini = value;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        int x = st.top();
        st.pop();
        if(x < mini){
            mini = 2*mini - x;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        int x = st.top();
        return x < mini ? mini : x;
    }
    
    int getMin() {
        return mini;
    }
};
int main()
{
    MinStack minStack;
    minStack.push(5);
    minStack.push(2);
    minStack.push(8);
    cout << minStack.getMin() << endl; // Output: 2
    minStack.pop();
    cout << minStack.top() << endl; // Output: 2
    return 0;
}