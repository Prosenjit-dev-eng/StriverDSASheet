#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t) {
    vector<int>hash(26,0);
    for(char ch : s) hash[ch - 'a']++;
    for(char ch : t) hash[ch - 'a']--;
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] != 0)
        {
            return false;
        }
        
    }
    return true;
}
int main()
{
    cout<<isAnagram("rat","cat")<<endl;
    return 0;
}