class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0)
                nums[i] = -1;
        }
        unordered_map<int, int> m; //sum, index
        int maxLen = 0, sum = 0;
        m[0] = -1; //!
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if(m.count(sum))
                maxLen = max(maxLen, i - m[sum]);
            else
                m[sum] = i; //first appearance
        }
        return maxLen;
    }
};

//这样碰到第二个sum值和之前sum值一样时候知道中间一段0 和 1的数目相等，-1 与 1数目相抵
