// Reverse a string in C++
#include<bits/stdc++.h>
using namespace std;
int lengthOfString(string str){
    int count = 0, i = 0;
    while (str[i]!= '\0')
    {
       count++;
       i++;
    }
    return count;
    
}
string reverseString(string str){
    int start = 0, end = str.size() - 1;
    while (start<end)
    {
        swap(str[start], str[end]);
        start++;
        end--;
    }
    
    return str;
}
int main()
{
    string s;
    cin>>s;
    cout<<"Length = "<<lengthOfString(s)<<endl;
    string reversed = reverseString(s);
    cout<<reversed<<endl;
    return 0;
}