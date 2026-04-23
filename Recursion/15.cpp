#include<bits/stdc++.h>
using namespace std;
// This structure should be remembered
// Print all subsets of an array
bool isPalindrome(string s,int start, int end){
    while (start<=end)
    {
        if(s[start++]!=s[end--]){
            return false;
        }
    }
    return true;
}

void func(int idx, string s, vector<string>&path, vector<vector<string>>&res){
    if (idx == s.length())
    {
        res.push_back(path);
        return;
    }
    for (int i = idx; i < s.size(); i++)
    {
        if(isPalindrome(s,idx,i)){
            path.push_back(s.substr(idx,i-idx+1));// cut
            func(i+1,s,path,res);
            path.pop_back();//when backtrack we have to create an empty path
        }
    }
    
    
}

vector<vector<string>>partition(string s){
   vector<vector<string>>res;
   vector<string>path;
   func(0,s,path,res);
   return res; 
}
int main()
{
    string s = "aab";
    vector<vector<string>> result = partition(s);

    for(auto partition : result){
        for(auto str : partition){
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}