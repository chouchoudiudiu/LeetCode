class Solution {
public: //complexity?
    bool find132pattern(vector<int>& nums) {
        if (nums.size() <= 2)
            return false;
        int n = nums.size(), i = 0, j = 0, k = 0;
        while (i < n) {
            while (i < n - 1 && nums[i] >= nums[i + 1])
                ++i;
            j = i + 1;
            while (j < n - 1 && nums[j] <= nums[j + 1])
                ++j;
            k = j + 1;
            while (k < n) {
                if (nums[k] > nums[i] && nums[k] < nums[j]) 
                    return true;
                ++k;
            }
            
            i = j + 1;
        }
        return false;
    }
}; //5436756...3-7-5
 /*
        我们就按顺序来找这三个数，首先我们来找第一个数，这个数需要最小，那么我们如果发现当前数字大于等于后面一个数字，我们就往下继续遍历，直到当前数字小于下一个数字停止。然后我们找第二个数字，这个数字需要最大，那么如果我们发现当前数字小于等于下一个数字就继续遍历，直到当前数字大于下一个数字停止。最后就找第三个数字，我们验证这个数字是否在之前两个数字的中间，如果没有找到，我们就从第二个数字的后面一个位置继续开始重新找这三个数字
        */
