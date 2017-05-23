class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> m;
        for (auto v : transactions) {
            m[v[0]] -= v[2]; //others owe you money
            m[v[1]] += v[2];
        }
        vector<int> accnt;
        for (auto v : m) {
            if(v.second != 0)
                accnt.push_back(v.second);
        }
        return helper(accnt, 0, 0);
    }
    
    int helper(vector<int> accnt, int start, int transfer) {// min number of transactions to settle starting from accnt[start]
        int res = INT_MAX;
        while (start < accnt.size() && !accnt[start])
            ++start;
        for (int i = start, prev = 0; i < accnt.size(); ++i) {
            if (accnt[i] != prev && accnt[start]*accnt[i] < 0) {
                accnt[i] += accnt[start]; //drop accnt[start]
                res = min(res, helper(accnt, start + 1, transfer + 1));
                prev = (accnt[i] -= accnt[start]);
            }
        }
        
        return res == INT_MAX ? transfer : res;
    }
}; //optimize where you could skip an index i if the same value a[i] has been tested before:
