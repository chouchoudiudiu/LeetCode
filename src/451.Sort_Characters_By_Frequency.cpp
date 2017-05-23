class Solution {
public:
    string frequencySort(string s) {
        string res;
        unordered_map<char, int> m;
        for (auto c : s)
            m[c]++;
        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> pq; //maxheap, no need to write comparator
        for (auto v : m)
            pq.push({v.second, v.first});
        
        while (!pq.empty()) {
            string s(pq.top().first, pq.top().second); //cnt, c
            res += s;
            pq.pop();
        }
        return res;
    }
};
