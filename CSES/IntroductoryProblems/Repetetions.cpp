#include<bits/stdc++.h>
using namespace std;
int repetetion(string s)
{
    int count = 1, max_count = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            count++;
            max_count = max(max_count, count);
        }
        else
        {
            count = 1;
        }
    }
    return max_count;

}
int main()
{
    string s;
    cin >> s;
    cout << repetetion(s) << endl;
    return 0;
}