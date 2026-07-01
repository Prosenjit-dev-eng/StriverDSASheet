#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()) return "";
    int n = strs.size();
    string first = strs[0];
    if(first.empty()) return "";
    for (int i = 1; i < n; i++)
    {
        int j = 0;
        while (j < first.size() && first[j] == strs[i][j] && j < n)
        {
            j++;
        }
        first = first.substr(0,j);
    }
    return first;
}
int main()
{
    vector<string>strs = {"dog","racecar","car"};
    cout<<longestCommonPrefix(strs)<<endl;
    return 0;
}