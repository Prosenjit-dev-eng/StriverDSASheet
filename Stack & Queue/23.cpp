#include<bits/stdc++.h>
using namespace std;
class LRUCache {
public:
    list<int>dll;
    map<int,pair</*Address*/list<int>::iterator,int>>cache;
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    void makeMostRecentlyUsed(int key){
        dll.erase(cache[key].first);// deletes the address of the key from the list
        dll.push_front(key);
        cache[key].first = dll.begin();// We find the mostrecently used's address by dll.begin()

    }
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1;
        }

        makeMostRecentlyUsed(key);
        return cache[key].second;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end())// if the key is present
        {
            cache[key].second = value;
            makeMostRecentlyUsed(key);
        }
        else
        {
            dll.push_front(key);
            cache[key] = {dll.begin(),value};
            n--;
        }
        // extra element
        if(n < 0){
            int keyDeleted = dll.back();
            cache.erase(keyDeleted);
            dll.pop_back();
            n++; 
        }
    }
};
int main()
{
    LRUCache* lru = new LRUCache(2);
    lru->put(1,1);
    lru->put(2,2);
    cout<<lru->get(1)<<endl;
    lru->put(3,3);
    cout<<lru->get(2)<<endl;
    lru->put(4,4);
    cout<<lru->get(1)<<endl;
    cout<<lru->get(3)<<endl;
    cout<<lru->get(4)<<endl;
    return 0;
}