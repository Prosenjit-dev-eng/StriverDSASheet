#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
    priority_queue<int>left;// Maxheap
    priority_queue<int,vector<int>,greater<int>>right;// Minheap

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (left.empty() || num < left.top())
        {
            left.push(num);
        }
        else right.push(num);

        // Always maintain size of left(+1) >= right
        if (abs((int)left.size() - (int)right.size()) > + 1)
        {
            right.push(left.top());
            left.pop();
        }
        else if (left.size() < right.size())
        {
            left.push(right.top());
            right.pop();
        }
        
        
    }
    
    double findMedian() {
        if (left.size() == right.size())// even
        {
            return (left.top() + right.top())/2.0;
        }
        else return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main()
{
    MedianFinder m;
    m.addNum(1);
    m.addNum(2);
    cout<<m.findMedian()<<endl;
    m.addNum(3);
    cout<<m.findMedian()<<endl;
    return 0;
}