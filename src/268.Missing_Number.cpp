class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long sum = n*(n + 1)/2;
        long long actual = accumulate(nums.begin(), nums.end(), 0);
        return sum - actual;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); ++i) 
            res ^= (i + 1)^nums[i];
        
        return res;
    }
};
