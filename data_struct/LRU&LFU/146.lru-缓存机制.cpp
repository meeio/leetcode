/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
#include <memory>
#include <unordered_map>

class node
{
public:
    node(int k, int v)
        : key(k)
        , val(v)
        , prev(nullptr)
        , next(nullptr)
    {
    }

    int   key, val;
    node* prev;
    node* next;
};

class double_list
{
public:
    double_list()
        : size(0)
        , tail(new node(0, 0))
        , head(new node(0, 0))
    {
        head -> next = tail;
        head -> prev = tail;
        tail -> next = head;
        tail -> prev = head;
    }

    // ~double_list()
    // {
    //     while ( size > 0 )
    //     {
    //         pop_back();
    //     }
    // }

    node* empalce_front(int k, int v)
    {
        node* new_node = new node(k, v);

        new_node->prev = head;
        new_node->next = head->next;

        head->next->prev = new_node;
        head->next       = new_node;

        return new_node;
    }

    void erase(node* t)
    {
        node* temp = t->prev;
        t->prev->next = t->next;
        t->next->prev = t->prev;
         
        delete t;
    }

    node* back()
    {
        return (tail->prev);
    }

    void pop_back()
    {
        if ( tail->prev == head )
        {
            return;
        }
        else
        {
            erase(tail->prev);
        }
    }

private:
    int size;

    node* tail;
    node* head;
};

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
        if ( auto it = key_to_val.find(key); it != key_to_val.end() )
        {
            node* tar = it->second;

            int val = tar->val;
            list.erase(tar);

            node* new_node  = list.empalce_front(key, val);
            key_to_val[key] = new_node;

            return val;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if ( auto it = key_to_val.find(key); it != key_to_val.end() )
        {
            node* tar = it->second;

            int val = tar->val;
            list.erase(tar);

            node* new_node  = list.empalce_front(key, value);
            key_to_val[key] = new_node;
        }
        else
        {
            if ( cap == max_cap )
            {
                node* tar = list.back();
                key_to_val.erase(tar->key);
                list.pop_back();
            }
            else
            {
                cap++;
            }
            node* new_node  = list.empalce_front(key, value);
            key_to_val[key] = new_node;
        }
    }

private:
    int                            cap, max_cap;
    double_list                    list;
    std::unordered_map<int, node*> key_to_val;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
