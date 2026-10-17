#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }

        int left = 0;
        int right = filtered.size() - 1;

        while (left < right) {
            if (filtered[left] != filtered[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;        
    }
};
int main()
{
    Solution s;
    string str = "A man, a plan, a canal: Panama";
    cout << (s.isPalindrome(str) ? "true" : "false") << endl;
    return 0;
}