#include<bits/stdc++.h>
using namespace std;
// permutation sequence

string getPermutation(int n, int k) {
        int fact=1;
        vector<int> nums;
        for(int i=1;i<n;i++){
            fact=fact*i;// (n-1)!
            nums.push_back(i);
        }
        nums.push_back(n);
        k=k-1;
        string ans="";
        while(true){
            ans=ans+to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            if(nums.size()==0){
                break;
            }
            k=k%fact;
            fact=fact/nums.size();
        }
        return ans;
    }

int main()
{
    string s = getPermutation(3,2);
    cout<<s<<endl;
    return 0;
}