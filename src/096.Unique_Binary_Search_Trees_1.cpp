class Solution {
public:

    int numTreeHelper(int n, vector<int>& nums)
    {
        if(nums[n] != -1)
            return nums[n];
            
        int sum = 0;
        for(int i = 1; i <= n; i++)
            sum += numTreeHelper(i - 1, nums)*numTreeHelper(n - i, nums); 

        nums[n] = sum;
        return sum;
    }
    int numTrees(int n) { //recursion
        vector<int> nums(n + 1, -1);
        nums[0] = 1;
        nums[1] = 1;
        
        return numTreeHelper(n, nums);
    }
};
