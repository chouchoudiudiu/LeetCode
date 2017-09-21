class LRUCache {
public:
    LRUCache(size_t capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        auto found_iter = m_map.find(key);
        if(found_iter == m_map.end()) //key doesn't exist
            return -1;
        m_cache.splice(m_cache.begin(), m_cache, found_iter->second);// void splice (iterator position, list& x, iterator i);
        return found_iter->second->second;//直接改变it->second的具体的值，例如重新指向cache开头 //move the node corresponding to key to front
    } //return value of the node
    
    void put(int key, int value) {
        auto found_iter = m_map.find(key);
        if(found_iter != m_map.end()) {
            m_cache.splice(m_cache.begin(), m_cache, found_iter->second);//move the node corresponding to key to front
            found_iter->second->second = value;//update value of the node
            return;
        }
        if(m_map.size() == m_capacity) {//reached capacity
            int key_to_del = m_cache.back().first;
            m_cache.pop_back(); //remove node in list;
            m_map.erase(key_to_del); //remove key in map
        }
        m_cache.emplace_front(key, value);//create new node in list
        m_map[key] = m_cache.begin();//create correspondence between key and node
    }
    
    size_t m_capacity;
    list<pair<int, int>> m_cache; //m_cache_iter->first: key, m_cache_iter->second: value;
    unordered_map<int, list<pair<int, int>>::iterator> m_map; //m_map_iter->first: key, m_map_iter->second: list iterator;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end())
            return -1;
        else {  
            cache.splice(cache.begin(), cache, it->second); // void splice (iterator position, list& x, iterator i);
            return it->second->second; //直接改变it->second的具体的值，例如重新指向cache开头
        }
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end())
            cache.erase(it->second); //若已存在，先删掉cache中它的*原始位置*
        cache.push_front({key, value}); //插到头部，修改m的key对应位置，不管是找没找到，都要放入头部，因为相当于新访问过
        m[key] = cache.begin();
        if (m.size() > cap) { //超过，去除之前cache里面最久最旧的数据
            m.erase(cache.back().first); //. 因为不是iterator
            cache.pop_back();
        }
    }
    
    list<pair<int, int>> cache;//key value pair
    unordered_map<int, list<pair<int, int>>::iterator> m;
    int cap;
};
//splice
           pair<int, int> hit = *(iter->second);
           cache.erase(iter->second);
           cache.push_front(hit);
           iter->second = cache.begin();
           return hit.second;
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
 
 //Typically LRU cache is implemented using a doubly linked list and a hash map.
/*LRU未满且key不存在：只需要创键(key, value)对，插入历史头部
LRU满了且key不存在：删除历史尾部(key, value)对，并插入历史头部
key存在／get：移动(key, value)到历史头部*/
