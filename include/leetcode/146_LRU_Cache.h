#include<unordered_map>
#include <iostream>
#include<string>
#include<algorithm>
#include<list>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    int get(int key) {
        if (dict.count(key) == 0) {
            return -1;
        }
        auto iter = dict[key];
        int value = iter->second;
        visitList.erase(iter);
        visitList.push_back(make_pair(key, value));

        dict[key] = --visitList.end();
        return value;
    }
    
    void put(int key, int value) {
        if (dict.count(key) > 0) {
            auto iter = dict[key];
    
            visitList.erase(iter);
            visitList.push_back(make_pair(key, value));
            dict[key] = --visitList.end();
            return;
        }

        if (dict.size() >= capacity) {
            auto del = visitList.begin();
            dict.erase(del->first);
            visitList.pop_front();
        }
        visitList.push_back(make_pair(key, value));
        dict[key] = --visitList.end();
    }
private:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator>dict;
    list<pair<int, int>>visitList;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */