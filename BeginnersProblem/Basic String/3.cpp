#include<bits/stdc++.h>
using namespace std;
    string largestOddNumber(string num) {
        // In C++, you cannot subtract a single character from an entire string. The - operator does not support this operation.
        // int number = num - '0'; NO
        for(int i = num.size() - 1; i >= 0; i--){
            if((num[i] - '0') & 1) return num.substr(0,i+1);
        }
        return "";
    }
int main()
{
    string num = "35427";
    cout << largestOddNumber(num) << endl;
    return 0;
}