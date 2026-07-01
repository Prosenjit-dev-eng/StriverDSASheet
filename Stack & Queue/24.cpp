#include<bits/stdc++.h>
using namespace std;

class LFUCache {
    int cap;
    int size;
    unordered_map<int,list<vector<int>>::iterator>cache;// key->Address
    map<int,list<vector<int>>> freq;// key->{key,value,counter}

public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    void makeMostFrequentlyUsed(int key){
        auto &vec = (*(cache[key]));

        int value = vec[1];
        int f = vec[2];
        freq[f].erase(cache[key]);
        if (freq[f].empty())
        {
            freq.erase(f);
        }
        f++;
        freq[f].push_front({key,value,f});

        cache[key] = freq[f].begin();
        
    }
    int get(int key) {
        if (cache.find(key) == cache.end())
        {
            return -1;
        }
        // We need the address (cache[key]), to get the vector
        auto vec = (*(cache[key]));
        int value = vec[1];
        makeMostFrequentlyUsed(key);
        return value;
    }
    
    void put(int key, int value) {
        if (cap == 0)
        {
            return;
        }
        if (cache.find(key) != cache.end())
        {
            auto &vec = (*(cache[key]));
            vec[1] = value;
            makeMostFrequentlyUsed(key);
        }
        else if(size < cap)
        {
            size++;
            //freshNode
            freq[1].push_front(vector<int>{key,value,1});
            cache[key] = freq[1].begin();
        }
        else{
            // time to remove lfu or lru
            auto &whichList = freq.begin()->second;
            int keyToDel = (whichList.back())[0];
            whichList.pop_back();
            cache.erase(keyToDel);
            if (whichList.empty()) freq.erase(freq.begin()->first);// mp erase key
            freq[1].push_front(vector<int>{key,value,1});
            cache.erase(keyToDel);
            cache[key] = freq[1].begin();
        }
        
    }
};
int main()
{
    LFUCache* lfu = new LFUCache(2);
    lfu->put(1,1);
    lfu->put(2,2);
    cout<<lfu->get(1)<<endl;
    lfu->put(3,3);
    cout<<lfu->get(2)<<endl;
    lfu->put(4,4);
    cout<<lfu->get(1)<<endl;
    return 0;
}