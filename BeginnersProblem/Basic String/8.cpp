#include<bits/stdc++.h>
using namespace std;
string frequencySort(string s) {
    unordered_map<char,int>hash;
    for(char ch : s) hash[ch]++;
    sort(s.begin(),s.end(),[&](char a, char b){
        if(hash[a] == hash[b]) return a < b;
        return hash[a] > hash[b];
    });
    return s;
}
int main()
{
    string s = "tree";
    cout << frequencySort(s) << endl;
    return 0;
}