#include<bits/stdc++.h>
using namespace std;
void solve(int idx, string s, string digits, vector<string>& ans, map<int, string>&mp){
    if(idx == digits.size()){
        ans.push_back(s);
        return;
    }
    int digit = digits[idx] - '0';
    for (int i = 0; i < mp[digit].size(); i++)
    {
        solve(idx+1,s+mp[digit][i],digits, ans,mp);
    }
    
}
vector<string> letterCombinations(string digits) {
    map<int, string> mp = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
    vector<string> ans;
    string s = "";
    if(digits.empty()) return ans;
    solve(0,s,digits,ans,mp);
    // int n = digits.size();
    // function<void(int, string)> backtrack = [&](int index, string current) {
    //     if(index == n) {
    //         ans.push_back(current);
    //         return;
    //     }
    //     int digit = digits[index] - '0';
    //     for(char ch : mp[digit]) {
    //         backtrack(index + 1, current + ch);
    //     }
    // };
    // backtrack(0, "");
    return ans;
}
int main()
{
    string digits ="23";
    vector<string> ans = letterCombinations(digits);
    for(string &ch : ans){
        cout<<ch<<endl;
    }
    return 0;
}