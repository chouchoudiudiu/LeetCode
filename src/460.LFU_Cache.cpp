class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (m.find(key) == m.end())
            return -1;
        //在freq中找到该key所在的list中的位置，因为要把它移到新的一层，freq加1
        mFreq[m[key].second].erase(mIter[key]); //pos in the list
        m[key].second++;
        mFreq[m[key].second].push_back(key); //新的一层
        mIter[key] = --mFreq[m[key].second].end(); //end是越过最后一个节点
        if (mFreq[minFreq].size() == 0)
            ++minFreq; //might be erased in first step
        return m[key].first;
    }
    
    void put(int key, int value) {
        if (cap <= 0)
            return;
        if (get(key) != -1) { //已存在，只需要update值 （不用改freq?）
            m[key].first = value;
            return;
        }
        if (m.size() >= cap) { //应该算是按时间顺序来的，最前面的去掉
            m.erase(mFreq[minFreq].front()); //always pushing from the back
            mIter.erase(mFreq[minFreq].front());
            mFreq[minFreq].pop_front(); //front, not back
        }
        m[key] = {value, 1}; //freq = 1
        mFreq[1].push_back(key);
        mIter[key] = --mFreq[1].end();
        minFreq = 1;
    }
    
private:
    int cap, minFreq;
    unordered_map<int, pair<int, int>> m; //key to {value,freq};
    unordered_map<int, list<int>>  mFreq;  //freq to key list;
    unordered_map<int, list<int>::iterator> mIter; //key to list iterator; 用于方便找到某个key在freq的list中的位置
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
