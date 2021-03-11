/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
#include <algorithm>
#include <list>
#include <unordered_map>

typedef std::pair<int, int> node;

class LRUCache
{
public:
    LRUCache(int capacity)
        : cap(0)
        , max_cap(capacity)
    {
    }

    int get(int key)
    {
        if ( auto it = key_to_it.find(key); it != key_to_it.end() )
        {
            auto node_it = it->second;
            int key = node_it -> first;
            int val = node_it -> second;
            list.erase(node_it);
            list.emplace_front(key, val);
            key_to_it[key] = list.begin();
            return val;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if ( auto it = key_to_it.find(key); it != key_to_it.end() )
        {
            auto node_it = it->second;
            list.erase(node_it);
            list.emplace_front(key, value);
            key_to_it[key] = list.begin();
        }
        else
        {
            if ( cap == max_cap )
            {
                node to_remove = list.back();
                key_to_it.erase(to_remove.first);
                list.pop_back();
            }
            else
            {
                cap++;
            }
            list.emplace_front(key, value);
            key_to_it[key] = list.begin();
        }
    }

private:
    int                                                cap, max_cap;
    std::list<node>                                    list;
    std::unordered_map<int, std::list<node>::iterator> key_to_it;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
