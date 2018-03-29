class Solution {
public:
//greedy
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, sum = 0;
        for (auto v:nums) {
            sum += v;
            sum = max(v, sum); //if adding v doesn't increase sum, evaluate which is larger, v must be a negative, original sum pos or neg
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};

//my own:
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int sum = nums[0], maxSum = nums[0];
        for(size_t i = 1; i < nums.size(); ++i) {
            if(sum < 0) 
                sum = 0;
            sum += nums[i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
