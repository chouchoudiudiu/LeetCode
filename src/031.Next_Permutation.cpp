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
           int j = upperSearch(nums, nums[i], i + 1, n - 1); //find the first number larger than nums[i]
           swap(nums[i], nums[j]);
       }
    }
};


/////previous permutation
class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers that's previous permuation
     */
    //1 3 2 4 5
    //先找到3，然后找到【2,4,5】中它的insert position j, 那么nums[j - 1]就是刚刚好小于它的那个数字，交换2,3
    //得到1,2,3,4,5；reverse [3,4,5] 得到1,2,5,4,3
    int lowerSearch (vector<int>& nums, int target, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (nums[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1; 
        }
        return low;
    } 
     
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
       int n = nums.size(), i = n - 2;
       for (; i >= 0; --i)
       {
           if (nums[i] > nums[i + 1])
               break;
       }
       if (i == -1) //not found, 3 2 1 case
           reverse(nums.begin(), nums.end());
       else {
           int j = lowerSearch(nums, nums[i], i + 1, n - 1); 
           swap(nums[i], nums[j - 1]);
           reverse(nums.begin() + i + 1, nums.end());
       }
       return nums;
    }
};
