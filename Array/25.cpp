#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Next permutation
void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int swappingIdx = -1;
        for(int i = n-1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                swappingIdx = i - 1;
                break;
            }
        }

        //find the just greater element of nums[swappingIdx]
        if(swappingIdx != -1){
            int idx = swappingIdx;
            for(int i = n-1; i >= swappingIdx; i--){
                if(nums[i] > nums[swappingIdx]){
                    idx = i;
                    break;
                }
            }
        
            swap(nums[swappingIdx], nums[idx]);
        }
        reverse(nums.begin()+swappingIdx+1,nums.end());
    }
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    nextPermutation(v);
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}