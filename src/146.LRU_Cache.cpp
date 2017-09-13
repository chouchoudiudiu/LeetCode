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
            return it->second->second; //直接改变it->second的具体的值
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
