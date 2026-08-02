// LC - 316 & 1081
#include<bits/stdc++.h>
using namespace std;
// String method
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int>lastIdx(26);
        string res = "";
        for(int i = 0; i < n; i++){
            lastIdx[s[i] - 'a'] = i;
        }
        vector<bool>hash(26,false);
        for(int i = 0; i < n; i++){
            char ch = s[i];
            int idx = ch - 'a';
            if(hash[idx]) continue;

            while(res.size() != 0 && res.back() > ch && lastIdx[res.back() - 'a'] > i){
                hash[res.back() - 'a'] = false;
                res.pop_back();
            }
            res += ch;
            hash[ch - 'a'] = true;
        }
        return res;
    }
    // Using stack
    string removeDuplicateLetters(string s) {
        int n = s.length();
        stack<char> st;
        
        vector<bool> taken(26, false);
        vector<int> lastIndex(26);
        
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            
            lastIndex[ch-'a'] = i;
        }
        
        
        for(int i = 0; i < n; i++) {
            
            int idx = s[i] - 'a';
            
            if(taken[idx] == true) continue;
            
            while(!st.empty()  && s[i] < st.top() && lastIndex[st.top() - 'a'] > i) {
                taken[st.top() - 'a'] = false;
                st.pop();
            }
            
            st.push(s[i]);
            taken[idx] = true;
            
        }
        
        string result;
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        
        reverse(begin(result), end(result));
        
        return result;
    }  
int main()
{
    cout<<removeDuplicateLetters("bcabc")<<endl;
    cout<<smallestSubsequence("bcabc")<<endl;

    return 0;
}