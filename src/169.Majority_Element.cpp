class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0, cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i] == majority) 
                ++cnt;
            else if(cnt == 0) {
                majority = nums[i];
                cnt = 1;
            }
            else
                --cnt;
        }
        return majority;
    }
};
