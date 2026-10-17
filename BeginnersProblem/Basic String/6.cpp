#include<bits/stdc++.h>
using namespace std;
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        string news = s+s;
        if(news.find(goal) != string::npos) return true;
        return false;
    }
int main()
{
    string s = "abcde";
    string goal = "cdeab";
    cout<<rotateString(s,goal)<<endl;
    return 0;
}