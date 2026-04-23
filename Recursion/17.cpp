#include<bits/stdc++.h>
using namespace std;
// Stack reverse
void insert(stack<int> &st, int ele){
    if(st.empty() || st.top() <= ele){
        st.push(ele);
        return;
    }

    int t = st.top();
    st.pop();
    insert(st,ele);
    st.push(t);
}
void sortStack(stack<int> &st){
    if(st.empty()) return;
    int t = st.top();
    st.pop();
    sortStack(st);
    insert(st,t);

}
int main(){
    stack<int>st;
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(7);
    st.push(6);


    sortStack(st);
    while (!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    
    return 0;
}
// T.C. = o(n^2)
// S.C. = o(n)