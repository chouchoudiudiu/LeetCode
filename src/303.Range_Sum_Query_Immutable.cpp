class NumArray {
public:
    NumArray(vector<int> nums) {
        sums.push_back(0);
        for (int i = 0; i < nums.size(); ++i)
            sums.push_back(sums.back() + nums[i]);
    }
    
    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
