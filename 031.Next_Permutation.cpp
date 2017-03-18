class Solution {
public:
    //1. scan from right to left, find the first index that num[i] < num[i+1]; such that the right are sorted
    //2. reverse nums from i+1 to the end, since it is sorted
    //3. find from i's right, the first number that is just larger than num[i], swap
    int upperSearch (vector<int>& nums, int target, int low, int high) {
        while (low < high) {
            int mid = low + (high - low)/2;
            if (nums[mid] <= target)
                low = mid + 1;
            else
                high = mid; //nums[high] 一定大于target, nums[low]一定小于等于target，交错时候，取high
        }
        return high;
    }
    
    void nextPermutation(vector<int>& nums) {
       int n = nums.size(), i = n - 2;
       for (; i >= 0; --i)
       {
           if (nums[i] < nums[i + 1])
               break;
       }
       if (i == -1) //not found, 3 2 1 case
           reverse(nums.begin(), nums.end());
       else {
           reverse(nums.begin() + i + 1, nums.end());
           int j = upperSearch(nums, nums[i], i, n - 1); //find the first number larger than nums[i]
           swap(nums[i], nums[j]);
       }
    }
};
