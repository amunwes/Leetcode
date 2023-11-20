// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.


class LRUCache {

public:
    unordered_map<int, list<pair <int, int>>::iterator> mp;
    list<pair <int, int>> lst;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {

        if (mp.find(key) != mp.end()){
            //use splice to move element to the right of the list in constant time.
            lst.splice(lst.end(), lst, mp[key]);
            return lst.back().second;
        }else{
            return -1;
        }
        
    }
    
    void put(int key, int value) {

        // if it exists already then replace it abd move to the back of the list.
        if(mp.find(key)!= mp.end())
            lst.erase(mp[key]);

        lst.push_back({key, value});
        mp[key] = --lst.end();
        
        if (mp.size() > cap){ // if we went over capacity
            int lru = lst.front().first;// retrieve the key at the front
            mp.erase(lru); // use the key to delete from map and pop the element from the list.
            lst.pop_front();
        }
        
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */