#include<bits/stdc++.h>
using namespace std;
// Stack reverse
void insertAtBottom(stack<int> &st, int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int t = st.top();
    st.pop();
    insertAtBottom(st,ele);// the rest stack
    st.push(t);
}
void reverseStack(stack<int> &st){
    // queue<int>q;
    // while (!st.empty())
    // {
    //     q.push(st.top());
    //     st.pop();
    // }
    // while (!q.empty())
    // {
    //     st.push(q.front());
    //     q.pop();
    // }

    // S.c. = o(n);
    /*if(st.empty()) return;
    int t = st.top();
    st.pop();// Trust
    reverseStack(st);
    stack<int>temp;
    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    st.push(t);
    while (temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }*/

    // S.c. = o(1)
    if(st.empty()) return;
    int t = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,t);
    
    
}
int main(){
    stack<int>st;
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(7);
    st.push(6);


    reverseStack(st);
    while (!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    
    return 0;
}