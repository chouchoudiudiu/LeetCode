class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int count = 1, i = 0; //count = 1
        while (++i < nums.size()) {
            if (count == 0) {
                count = 1;
                majority = nums[i];
            }
            else if (nums[i] == majority)
                ++count;
            else
                --count;
        }
        return majority;
    }
};
