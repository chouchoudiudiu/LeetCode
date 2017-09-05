class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> m; //sorted
        for(auto v : nums)
            ++m[v];
        int maxLen = 0;
        for(auto v : m) {
            int val = v.first;
            int cnt = v.second;
            if(m.find(val - 1) != m.end())
                maxLen = max(maxLen, cnt + m[val - 1]); //can use all 3.2.3...抽出来即可
        }
        return maxLen;
    }
};
//[1,1,1,1]  exactly 1.
