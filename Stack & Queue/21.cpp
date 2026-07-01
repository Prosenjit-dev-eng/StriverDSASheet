#include<bits/stdc++.h>
using namespace std;

    bool isValid(string s) {
        stack<char>st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            char c = s[i];
            if(c == '(' || c == '{' || c == '[') st.push(c);
            else{
                if(st.empty()) return false;
                if ((c == ')' && st.top() != '(') || 
                    (c == '}' && st.top() != '{') || 
                    (c == ']' && st.top() != '[')) 
                    return false;

                    st.pop();
            }
        }
        return st.empty();
    }
int main()
{
    string s = "({(()}))[]";
    cout<<isValid(s)<<endl;
    return 0;
}