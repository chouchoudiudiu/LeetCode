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
