#ifndef LRU_H
#define LRU_H
#include <bits/stdc++.h>
using namespace std;

template<typename K, typename V>

struct LRU_Node
{
    LRU_Node(K key, V val)
    {
        this->_key = key;
        this->_val = val;
    }
    K _key;
    V _val;
};

template<typename K, typename V>
class LRU
{
public:
    LRU(int cap)
    {
        this->_capacity = cap;
        this->_map = unordered_map<K, LRU_Node<K,V>>();
        this->_list = list<LRU_Node<K, V>>();
    } 
    ~LRU(){}
private:    
    void make_recent(K key)
    {
        if(!this->_map.count(key)) return;
        LRU_Node<K,V> node = this->_map[key];
        this->_list.remove(node);
        this->_list.push_back(node);
    }
    int _capacity;
    list<LRU_Node<K,V>> _list;
    unordered_map<K, LRU_Node<K, V>> _map;
};



#endif // !LRU_H