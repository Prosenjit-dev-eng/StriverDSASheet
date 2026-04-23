#include<bits/stdc++.h>
using namespace std;
// Stack using queue
class StackUsingQueue {
    public:
    queue<int> q;
    void append(int x){
        int curr_size = q.size();
        q.push(x);
        for (int i = 1; i <= curr_size; i++)
        {
            q.push(q.front());
            q.pop();
        }
        
    }
    int deleteele(){
        int n = q.front();
        q.pop();
    }
    int Top(){
        return q.front();
    }
    int size(){
        return q.size();
    }
};    
    

int main()
{
    StackUsingQueue s;
    s.append(1);
    s.append(2);
    s.append(3);
    cout << "Top element is: " << s.Top() << endl;
    cout << "Stack size is: " << s.size() << endl;
    s.deleteele();
    cout << "Top element after pop is: " << s.Top() << endl;
    cout << "Stack size after pop is: " << s.size() << endl;
    return 0;
}

    