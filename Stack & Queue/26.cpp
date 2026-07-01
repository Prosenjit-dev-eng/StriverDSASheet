#include<bits/stdc++.h>
using namespace std;
class StockSpanner {
    stack<pair<int,int>>s;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt = 1;
        while (!s.empty() && s.top().first <= price)
        {
            cnt += s.top().second;
            s.pop();
        }
        s.push({price,cnt});
        
    }
};
int main()
{
    return 0;
}