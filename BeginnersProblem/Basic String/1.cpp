#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size()-1;
        while (i<j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
};
int main()
{
    Solution s;
    vector<char> str = {'h','e','l','l','o'};
    s.reverseString(str);
    for (char c : str) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}