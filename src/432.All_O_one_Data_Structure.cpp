class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
       /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (!m.count(key)) {
            if (buckets.empty() || buckets.back().val != 1) {
                auto newBucket = buckets.insert(buckets.end(), {1, {key}});
                m[key] = newBucket;
            } else {
                auto newBucket = --buckets.end();
                newBucket->keys.insert(key);
                m[key] = newBucket;
            }
        } else {
            auto curBucket = m[key], lastBucket = (--m[key]);
            if (lastBucket == buckets.end() || lastBucket->val != curBucket->val + 1) {
                auto newBucket = buckets.insert(curBucket, {curBucket->val + 1, {key}});
                m[key] = newBucket;
            } else {
                lastBucket->keys.insert(key);
                m[key] = lastBucket;
            }
            curBucket->keys.erase(key);
            if (curBucket->keys.empty()) buckets.erase(curBucket);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (!m.count(key)) return;
        auto curBucket = m[key];
        if (curBucket->val == 1) {
            curBucket->keys.erase(key);
            if (curBucket->keys.empty()) buckets.erase(curBucket);
            m.erase(key);
            return;
        }
        auto nextBucket = ++m[key];
        if (nextBucket == buckets.end() || nextBucket->val != curBucket->val - 1) {
            auto newBucket = buckets.insert(nextBucket, {curBucket->val - 1, {key}});
            m[key] = newBucket;
        } else {
            nextBucket->keys.insert(key);
            m[key] = nextBucket;
        }
        curBucket->keys.erase(key);
        if (curBucket->keys.empty()) buckets.erase(curBucket);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin()); //or end()?
    }
private: 
    struct Bucket
    {
        int val; //出现次数
        unordered_set<string> keys; //存次数相同的所有key值
    };
    list<Bucket> buckets; //按value大小从大到小排列
    unordered_map<string, list<Bucket>::iterator> m; //key value
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
