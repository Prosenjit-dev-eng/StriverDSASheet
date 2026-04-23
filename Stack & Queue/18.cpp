#include<bits/stdc++.h>
using namespace std;
 int trap(vector<int>& height) {
     // vector<int> prefixSum(n,0);
     // vector<int> suffixSum(n,0);
     // // Prefix Sum
     // prefixSum[0] = height[0];
     // for(int i = 1; i < n; i++){
        //     prefixSum[i] = max(prefixSum[i-1],height[i]);
        // }
        // // Suffix sum
        // suffixSum[n - 1] = height[n-1];
        // for(int i = n-2; i >= 0; i--){
            //     suffixSum[i] = max(suffixSum[i+1],height[i]);
            // }
            
            // int watertrapped = 0;
            // for(int i = 0; i < n; i++){
                //     watertrapped+= min(prefixSum[i],suffixSum[i]) - height[i];
                // }
                // return watertrapped;
        int n = height.size();
        int watertrapped = 0, l = 0, r = n-1;
        int lmax = 0, rmax = 0;
        while(l<r){
            lmax = max(lmax,height[l]);
            rmax = max(rmax,height[r]);
            if(lmax < rmax){
                watertrapped += (lmax-height[l]);
                l++;
            }
            else{
                watertrapped += (rmax-height[r]);
                r--;
            }

        }
        return watertrapped;
    }

int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height) << endl;
    return 0;
}