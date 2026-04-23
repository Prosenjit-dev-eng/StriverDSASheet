// Write an API that generates fancy sequences using the append, addAll, and multAll operations.

// Implement the Fancy class:

// Fancy() Initializes the object with an empty sequence.
// void append(val) Appends an integer val to the end of the sequence.
// void addAll(inc) Increments all existing values in the sequence by an integer inc.
// void multAll(m) Multiplies all existing values in the sequence by an integer m.
// int getIndex(idx) Gets the current value at index idx (0-indexed) of the sequence modulo 109 + 7. If the index is greater or equal than the length of the sequence, return -1
#include<bits/stdc++.h>
using namespace std;
class Fancy{
    vector<long long>seq;
    int cnt;
    public:
    Fancy() {
        seq.clear();
        cnt++;
    }
    
    void append(int val) {
        seq.push_back(val);
    }
    
    void addAll(int inc) {
        for (long long &i : seq)
        {
            i+=inc;
        }
        
    }
    
    void multAll(int m) {
        for (long long &i : seq)
        {
            i*=m;
        }
    }
    
    int getIndex(int idx) {
        return idx < seq.size() ? seq[idx] % 1000000007 : -1;
    }
};
int main()
{
Fancy fancy = new Fancy();
fancy.append(2);   // fancy sequence: [2]
fancy.addAll(3);   // fancy sequence: [2+3] -> [5]
fancy.append(7);   // fancy sequence: [5, 7]
fancy.multAll(2);  // fancy sequence: [5*2, 7*2] -> [10, 14]
fancy.getIndex(0); // return 10
fancy.addAll(3);   // fancy sequence: [10+3, 14+3] -> [13, 17]
fancy.append(10);  // fancy sequence: [13, 17, 10]
fancy.multAll(2);  // fancy sequence: [13*2, 17*2, 10*2] -> [26, 34, 20]
fancy.getIndex(0); // return 26
fancy.getIndex(1); // return 34
fancy.getIndex(2); // return 20
    return 0;
}