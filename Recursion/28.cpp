#include<bits/stdc++.h>
using namespace std;
    bool f(int idx, string& s,unordered_set<string>& st,vector<int>& dp) {

        if (idx == s.size())
            return true;

        if (dp[idx] != -1)
            return dp[idx];

        string curr = "";

        for (int j = idx; j < s.size(); j++) {

            curr += s[j];

            if (st.count(curr)) {

                if (f(j + 1, s, st, dp))
                    return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> st(wordDict.begin(),
                                 wordDict.end());

        vector<int> dp(s.size(), -1);

        return f(0, s, st, dp);
    }
int main()
{
    string s = "takeuforward";
    vector<string>wordDict = {"take", "forward", "you", "u"};
    cout<<wordBreak(s,wordDict)<<endl;
    return 0;
}