#include<bits/stdc++.h>
using namespace std;
// Postfix to Infix Conversion

bool isOperand(char c){
    return isalnum(c);
}
void postfixToInfix(string s){
    stack<string>st;
    for(int i = 0; i < s.length(); i++){
        if(isOperand(s[i])){
            st.push(string(1, s[i]));
        }
        else{
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            string conc = "(" + t2 + s[i] + t1 + ")";
            st.push(conc);
        }
    }
    cout << st.top() << endl;
}
int main()
{
    string exp = "PQ+MN-*";
    cout << "Infix expression: " << exp << endl;
    postfixToInfix(exp);
    return 0;
}