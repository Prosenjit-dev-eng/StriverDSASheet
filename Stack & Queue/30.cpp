#include<bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int maxArea = 0, element,nse,pse;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            element = st.top();
            st.pop();
        nse = i, pse = st.empty() ? -1 : st.top();
        maxArea = max(maxArea, heights[element] * (nse - pse - 1));
        }
        st.push(i);
        
    }
    // Clear stack for right side calculation
    while (!st.empty()) {
        nse = n;
        element = st.top();
        st.pop();
        pse = st.empty() ? -1 : st.top();
        maxArea = max(maxArea, heights[element] * (nse - pse - 1));
    }
    return maxArea;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int>heights(n,0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1)
            {
                heights[j]++;
            }
            
        }
        
    }
    return largestRectangleArea(heights);
    
}
int main()
{
    
    return 0;
}