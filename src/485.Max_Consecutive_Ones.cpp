class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cnt = 0;
        for(auto v : nums) {
            if(v == 1) {
                ++cnt;
                res = max(cnt, res);
            }
            else //v == 0
                cnt = 0;
        }
        return res;
    }
};
/////////////////////////////////////////////////////////////
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen = 0, i = 0, j = 0;
        bool on = false;
        for(; i < nums.size(); ++i) {
            if(nums[i] == 1 && !on) {
                on = true;
                j = i;
            }
            if(nums[i] == 0 && on) {
                on = false;
                maxLen = max(maxLen, i - j);
            }
        }
        return on ? max(maxLen, i - j) : maxLen;
    }
};
