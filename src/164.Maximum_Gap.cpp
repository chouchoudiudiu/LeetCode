class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int mx = nums[0], mn = nums[0];
        for (auto v : nums) {
            mx = max(v, mx);
            mn = min(v, mn);
        }
        int binSize = (mx - mn)/n + 1;
        int totalBins = (mx - mn)/binSize + 1;
        vector<int> mins(totalBins, INT_MAX);
        vector<int> maxs(totalBins, INT_MIN);
        set<int> s;
        for (auto v : nums) {
            int idx = (v - mn)/binSize;
            mins[idx] = min(mins[idx], v);
            maxs[idx] = max(maxs[idx], v);
            s.insert(idx);
        }
        int internalMax = INT_MIN, externalMax = INT_MIN, prevMax = INT_MAX;
        for (auto iter = s.begin(); iter != s.end(); ++iter) {
            internalMax = max(internalMax, maxs[*iter] - mins[*iter]);
            if (prevMax != INT_MAX) //NOT THE FIRST IDX
                externalMax = max(externalMax, mins[*iter] - prevMax);
            prevMax = maxs[*iter];
        }
        return max(internalMax, externalMax);
    }
};
