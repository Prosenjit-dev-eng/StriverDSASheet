#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
       if(strs.empty()) return "";
       string first = strs[0];
       if(first.empty()) return "";

       for(int i = 1; i < strs.size(); i++){
            int j = 0; 
            while(j < first.size() && j < strs[i].size() && first[j] == strs[i][j]){
                j++;
            }
            first = first.substr(0,j);

       }
        return first;
    }
int main()
{
    vector<string>strs = {"flower","flow","flight"};
    cout<<longestCommonPrefix(strs)<<endl;
    return 0;
}