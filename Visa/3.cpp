#include<bits/stdc++.h>
using namespace std;
/*
(i) Here Entry = -1 & Exit = +1 , for difference array we store it , then we do cumulative sum to find what I have to add for each character
(ii) In Diff array for [L,R] => A[l] += x, and A[r+1] -= x, the we do cumsum
*/
vector<int> findMaxGuests(vector<int>&entry, vector<int>&exit){
    int n = entry.size();
    int maxOfEntry = *max_element(entry.begin(),entry.end());
    int maxOfExit = *max_element(exit.begin(),exit.end());
    int maxLimit = max(maxOfEntry,maxOfExit);// The range of diffArray
    vector<int>diffArr(maxLimit+1,0);// DifferenceArray
    for (int i = 0; i < n; i++)
    {
        diffArr[entry[i]] += 1;
        if(diffArr[exit[i]+1] < n) diffArr[exit[i]+1] -= 1;
    }
    vector<int>cumsum(maxLimit+1,0);
    cumsum[0] = diffArr[0];
    for (int i = 1; i <= maxLimit; i++)
    {
        cumsum[i] = diffArr[i] + cumsum[i-1];
    }
    int maxi = -1, maxVal = INT_MIN;
    for (int i = 0; i < cumsum.size(); i++)
    {
        if (cumsum[i] > maxVal)
        {
            maxi = i;
            maxVal = cumsum[i];
        }
        
    }
    return {maxVal,maxi};

}
int main()
{
    vector<int>entry = {1,2,9,5,5};
    vector<int>exit = {4,5,12,9,12};
    vector<int>ans = findMaxGuests(entry,exit);
    cout<<"Max Guests: "<<ans[0]<<" at Time: "<<ans[1]<<endl;
    return 0;
}