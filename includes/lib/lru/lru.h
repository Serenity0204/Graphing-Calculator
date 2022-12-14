#ifndef LRU_H
#define LRU_H
#include <bits/stdc++.h>
using namespace std;



template<class K, class V>
class LRU
{
public:
    template <typename Key, typename Val>
    friend ostream& operator <<(ostream& outs, const LRU<Key, Val>& printMe)
    {
        outs << "map: " << endl;
        for(const auto& x : printMe._map)
        {
            outs << "key: " << x.first << endl;
            outs << "val: " << x.second << endl;
        }
        outs << endl;
        outs << "list: ";
        for(const auto& x : printMe._list)
        {
            outs << x << " ";
        }
        outs << endl;
        return outs;
    }

    LRU(){}
    LRU(int cap)
    {
        this->_capacity = cap;
        this->_map = unordered_map<K,V>();
        this->_list = list<K>();
    } 

    ~LRU(){}
    const K& operator [](int index)
    {
        int count = 0;
        for(const auto& x: this->_list)
        {
            if(count == index) return x;
        }
    }   
    V get(K key)
    {
        if(!this->_map.count(key)) return V();
        this->make_recent(key);
        return this->_map[key];
    }
    void put(K key, V val)
    {
        if(this->_map.count(key))
        {
            this->delete_key(key);
            this->add_recent(key, val);
            this->_map[key] = val;
            return;
        }
        if(this->_capacity == this->_list.size()) this->remove_latest_unused();
        this->add_recent(key, val);
    }
private:    
    void make_recent(K key)
    {
        if(!this->_map.count(key)) return;
        V val = this->_map[key];
        this->_list.remove(key);
        this->_list.push_back(key);
    }
    
    void add_recent(K key, V val)
    {
        //V val = LRU_Node<K, V>(key, val);
        this->_list.push_back(key);
        this->_map[key] = val;
    }

    void delete_key(K key)
    {
        if(!this->_map.count(key)) return;
        V val = this->_map[key];
        this->_list.remove(key);
        this->_map.erase(key);
    }

    void remove_latest_unused()
    {
        if(this->_list.size() == 0 && this->_map.size() == 0) return;
        K key = this->_list.front();
        this->_list.pop_front();
        this->_map.erase(key);
    }

//private:
    int _capacity;
    list<K> _list;
    unordered_map<K,V> _map;
};


    
#endif // !LRU_H