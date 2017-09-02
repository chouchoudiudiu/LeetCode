class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] < nums[i - 1]) {
                ++cnt;
                if(i < 2 || nums[i - 2] <= nums[i])
                    nums[i - 1] = nums[i]; //lower nums[i - 1]
                else
                    nums[i] = nums[i - 1]; //rise nums[i]
            }
            if(cnt > 1)
                return false;
        }
        return true;
    }
};
//[1,1,1]
//TLE if use LIS DP (non decreasing) 这个问题又让我回头去看LIS 发现自己之前的理解有问题。。。的确最后的解可能不是正确的subsequence.
//网上还有一些做法能够给出正确的subsequence
//http://www.geeksforgeeks.org/construction-of-longest-monotonically-increasing-subsequence-n-log-n/
/*
http://massivealgorithms.blogspot.com/2017/08/leetcode-665-non-decreasing-array.html

This problem is like a greedy problem. (but this solution causes )
When you find nums[i-1] > nums[i] for some i, you will prefer to change nums[i-1]'s value, 
since a larger nums[i] will give you more risks that you get inversion errors after position i. 
But, if you also find nums[i-2] > nums[i], then you have to change nums[i]'s value instead, 
or else you need to change both of nums[i-2]'s and nums[i-1]'s values.
Example:
 0 ..  i ...
 1 1 2[4]2 5   we can just raise a[i+1] to 4;
         4
 1 1 2[4]2 3   in this case lower a[i] is better;
 (/)
