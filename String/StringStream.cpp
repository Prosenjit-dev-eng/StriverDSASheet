#include<bits/stdc++.h>
using namespace std;
vector<string> getToken(string s){
    vector<string> tokens;
    stringstream ss(s);
    string token = "";
    while (getline(ss,token,'.'))
    {
        tokens.push_back(token);
    }
    return tokens;
    
}
int compareVersion(string version1, string version2) {
    vector<string>v1 = getToken(version1);
    vector<string>v2 = getToken(version2);
    // Pad both vectors to equal size
    while(v1.size() < v2.size()) v1.push_back("0");//1
    while(v1.size() > v2.size()) v2.push_back("0");//1.0.0.0, so it can't be done if condition use while  loop
    int i = 0;
    while (i < v1.size())
    {
        int a = stoi(v1[i]);
        int b = stoi(v2[i]);
        if(a > b) return 1;
        if(a < b) return -1;
        i++;
    }
    return 0;

}
int main()
{
    cout<<compareVersion("1.0.0.2","1")<<endl;
    return 0;
}