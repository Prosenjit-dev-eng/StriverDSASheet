#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t) {
    unordered_map<char,int> freq1, freq2;

    for(char c : s) freq1[c]++;
    for(char c : t) freq2[c]++;

    // Compare the two maps directly
    return freq1 == freq2;
}
int main()
{
    string s = "anagram", t = "nagaram";
    cout<<isAnagram(s,t)<<endl;

    return 0;
}