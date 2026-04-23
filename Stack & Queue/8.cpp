// Infix to Prefix Conversion using Stack
#include<bits/stdc++.h>
using namespace std;
int priority(char c){
    if(c == '+' || c == '-') return 1;
    else if(c == '*' || c == '/') return 2;
    else if(c == '^') return 3;
    return -1;

}
void infixToPrefix(string s){
    int i = 0;
    string ans = "";
    stack<char>st;
    // Reverse
    reverse(s.begin(),s.end());
    // Reverse the brackets
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == ')') s[i] = '(';
        else if(s[i] == '(') s[i] = ')';

    }
    
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
            if(!st.empty()) st.pop();// Remove '('
        }
        // Operator part
        else
        {
            if(s[i] == '^'){
                while (!st.empty() && priority(s[i]) <= priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            
            }
            else{
                while (!st.empty() && priority(s[i]) < priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
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
    // Reverse the answer to get the prefix expression  
    reverse(ans.begin(), ans.end());
    // Output the result
    cout<<"Prefix expression: "<<ans<<endl;
}
int main()
{
  string exp = "(p+q)*(m-n)";
  cout << "Infix expression: " << exp << endl;
  infixToPrefix(exp);
    return 0;
}