// Infix to Postfix Conversion using Stack
#include<bits/stdc++.h>
using namespace std;
int priority(char c){
    if(c == '+' || c == '-') return 1;
    else if(c == '*' || c == '/') return 2;
    else if(c == '^') return 3;
    return -1;

}
void infixToPostfix(string s){
    int i = 0;
    string ans = " ";
    stack<char>st;
    // For operators and brackets
    while (i < s.size())
    {
        if((s[i] >= 'a' && s[i] <='z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i]<='9')){
            // If operand add into answer
            ans += s[i];
        }
        // If brackets
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
            // pop and to output string from the stack
            // until an ‘(‘ is encountered.
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top()!='(' )
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        // Operator part
        else
        {
          while (!st.empty() && priority(s[i])<=priority(st.top()))
          {
            ans += st.top();
            st.pop();
          }
            st.push(s[i]);
        }
        
        i++;
    }
    // Pop all the remaining elements from the stack
    while (!st.empty())
    {
     ans += st.top();
     st.pop();   
    }
    cout<<"Postfix expression: "<<ans<<endl;
    
}
int main(){
  string exp = "(p+q)*(m-n)";
  cout << "Infix expression: " << exp << endl;
  infixToPostfix(exp);
    return 0;
}