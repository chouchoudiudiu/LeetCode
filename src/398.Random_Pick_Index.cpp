class Solution {
public:
 //reservior sampling
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int n = nums.size(), cnt = 0, first = 0, res = 0; //must exist
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                ++cnt;
                res = first = i;
                break;
            }
        }
        
        for (int i = first + 1; i < n; ++i) {
            if (nums[i] == target) {
                ++cnt;
                int j = rand()%cnt;
                if (j == 0)
                    res = i;
            }
        }
        return res;
    }
    vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
