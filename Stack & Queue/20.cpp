#include<bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int>res;
        stack<int>st;
        st.push(asteroids[0]);
        for(int i = 1; i < n; i++){
            if (asteroids[i] > 0) st.push(asteroids[i]);

            else
            {
                while (!st.empty() && st.top() > 0 && (st.top() < abs(asteroids[i])))
                {
                    st.pop();
                }
            // Equal case
            if (!st.empty() && st.top() == abs(asteroids[i]))
            {
                st.pop();
            }
            // Same negative case or empty case
            else if (st.empty() || st.top() < 0)
            {
                st.push(asteroids[i]);
            }
            }
        }
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
}
int main()
{
    vector<int>asteroids = {5,10,-5};
    vector<int>res = asteroidCollision(asteroids);
    for(auto x: res) cout<<x<<" ";
    return 0;
}