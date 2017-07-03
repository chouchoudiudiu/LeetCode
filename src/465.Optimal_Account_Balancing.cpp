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
        while(start < accnt.size() && accnt[start] == 0)
            ++start;
        for(int i = start + 1; i < accnt.size(); ++i) {
            if(accnt[start]*accnt[i] < 0) {
                accnt[i] += accnt[start];
                res = min(res, helper(accnt, start + 1, transfer + 1));
                accnt[i] -= accnt[start];
            }
        }
        return res == INT_MAX ? transfer : res;
    }
    }
}; //optimize where you could skip an index i if the same value a[i] has been tested before:
