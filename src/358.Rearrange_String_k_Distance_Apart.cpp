class Solution {
public:
//greedy
    string rearrangeString(string s, int k) {
        if (k == 0)
            return s;
        int len = s.size();
        string res;
        unordered_map<char, int> m; //freq ? int freq[256]
        priority_queue<pair<int, char>> pq;
        for (auto c : s)
            ++m[c];
        for (auto v : m)
            pq.push({v.second, v.first});
        while (!pq.empty()) {
            vector<pair<int, int>> usable;
            int cnt = min(k, len);
            for (int i = 0; i < cnt; ++i) {
                if (pq.empty()) return ""; //return !!!
                auto t = pq.top();
                pq.pop();
                res += t.second;
                if (--t.first > 0)
                    usable.push_back(t);
                --len; //don't forget
            }
            for (auto v : usable)
                pq.push(v);
        }
        return res;
    }
};
