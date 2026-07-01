#include<bits/stdc++.h>
using namespace std;
string reverseWords(string s) {
    int n = s.size();
    int i = 0;
    vector<string>words;
    while (i < n)
    {
        while(i<n && s[i] == ' ')
        {
            i++;// skipping spaces
        }
        if(i >= n) break;// s = "hello     "
        string word = "";
        while (i < n && s[i] != ' ')
        {
            word += s[i];
            i++;
        }
        words.push_back(word);
    }

    string ans = "";
    for(int i = words.size() - 1; i >= 0; i--){
        ans += words[i];
        if(i != 0) ans += " ";// at last we don't give a space
    }
    return ans;
}
/*
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        stringstream ss(s);// cin >> words without spaces
        string word,result="";
        while(ss >> word)
        {
            reverse(word.begin(),word.end());
            if(!result.empty())
                result += " ";// after every we need to add spaces
            result += word;
        }
        return result;
    } */
int main()
{
    string s = "  hello world  ";
    cout<<reverseWords(s)<<endl;
    return 0;
}