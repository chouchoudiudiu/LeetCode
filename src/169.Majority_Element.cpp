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


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0], cnt = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(cnt == 0)
                majority = nums[i];
            if(nums[i] == majority)
                ++cnt;
            else
                --cnt;
        }
        return majority;
    }
};
