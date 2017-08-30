class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cum = 0, cnt = 0;
        unordered_map<int, int> m; //prefix sum, cnt
        m[0] = 1;
        for(int i = 0; i < nums.size(); ++i) {
            cum += nums[i];
            cnt += m[cum - k]; //not k - cum!
            m[cum]++;
        }
        return cnt;
    }
};
