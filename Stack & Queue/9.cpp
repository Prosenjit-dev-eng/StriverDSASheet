#include<bits/stdc++.h>
using namespace std;
// Prefix to Infix Conversion

bool isOperand(char c){
    return isalnum(c);
}
void prefixToInfix(string s){
    stack<string>st;
    for(int i = s.length()-1; i >= 0; i--){
        if(isOperand(s[i])){
            st.push(string(1, s[i]));
        }
        else{
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            string conc = "(" + t1 + s[i] + t2 + ")";
            st.push(conc);
        }
    }
    cout << st.top() << endl;
}
int main()
{
    string exp = "*+PQ-MN";
    cout << "Infix expression: " << exp << endl;
    prefixToInfix(exp);
    return 0;
}