class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0, cnt = 0;
        for (auto v : nums) {
            if (v == 1) 
                max = max > ++cnt ? max : cnt;
            else
                cnt = 0; //meet 0, reset the 1 counter
        }
        
        return max;
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
