class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> m;
        for (auto v : nums) {
            ++m[v];
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //min heap
        for (auto v : m) {
            pq.push({v.second, v.first}); //count, value
            if (pq.size() > k) 
                pq.pop();//pop the smallest one
        }
        while (!pq.empty()) {
            res.push_back(pq.top().second); //actual value
            pq.pop();
        }
        
        return vector<int>(res.rbegin(), res.rend());
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m; //val, cnt
        vector<int> res;
        for(auto v : nums)
            ++m[v];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //cnt, val
        for(auto v : m) {
            if(pq.size() < k) {
                pq.push({v.second, v.first});
            }
            else {
                if(v.second > pq.top().first) { //v.second > pq.top().first
                    pq.pop();
                    pq.push({v.second, v.first});
                }
            }
        }
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return vector<int>(res.rbegin(), res.rend());
    }
};

/* 无法保证是按顺序输出的,第一第二第三
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> m;
        for (auto v : nums) {
            ++m[v];
        }
        priority_queue<pair<int, int>> pq; //maxheap, pair default sort by first
        for (auto v : m) {
            pq.push({v.second, v.first}); //count, value
            if (pq.size() > m.size() - k) { //最多pop出m.size() - k次
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        
        return res;
    }
};
*/

//bucket sort?
