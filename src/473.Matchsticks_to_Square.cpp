class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4)
            return false;
        long sum = accumulate (nums.begin(), nums.end(), 0);
        int side = sum/4;//divide by 4
        int max = *max_element(nums.begin(), nums.end());
        if (sum%4 != 0 || max > side) //有的边比要求的边长长，因为需要全部用掉，不可以
            return false;
        long sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
        sort(nums.begin(), nums.end(), greater<int>());//逆序，or sort(nums.rbegin(), nums.rend())
        return dfs(sum1, sum2, sum3, sum4, nums, 0, side); //side is target
    }
    
    bool dfs (long sum1, long sum2, long sum3, long sum4, vector<int>& nums, int i, int target) {
        if (sum1 > target || sum2 > target || sum3 > target || sum4 > target)
            return false;
        if (i == nums.size()) {
            return sum1 == target && sum2 == target && sum3 == target;
        }
        //check nums[i] belonging to side1,side2,side3,side4
        return dfs(sum1 + nums[i], sum2, sum3, sum4, nums, i + 1, target) || 
        dfs(sum1, sum2 + nums[i], sum3, sum4, nums, i + 1, target) ||
        dfs(sum1, sum2, sum3 + nums[i], sum4, nums, i + 1, target) ||
        dfs(sum1, sum2, sum3, sum4 + nums[i], nums, i + 1, target);
    }
}; //[5,5,5,5,4,4,4,4,3,3,3,3]
