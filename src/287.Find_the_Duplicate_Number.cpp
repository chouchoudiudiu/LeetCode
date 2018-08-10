class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1; //n
        while (low < high) { //otherwise wont stop
            int count = 0;
            int mid = low + (high - low)/2;
            for (auto v : nums) {
                if (v <= mid) //not nums[mid]...
                    ++count;
            }
            if (count > mid) //if not in mid, it should be equal
                high = mid; //mid itself is possible
            else
                low = mid + 1;            
        }
        return low; //low == high == mid
    }
};

//a binary search for 1 - n, not related to nums itself
//https://en.wikipedia.org/wiki/Pigeonhole_principle
//You must not modify the array (assume the array is read only). //NO SORT...
/*At first the search space is numbers between 1 to n. Each time I select a number mid (which is the one in the middle) and 
count all the numbers equal to or less than mid. Then if the count is more than mid, the search space will be [1 mid] otherwise 
[mid+1 n]. I do this until search space is only one number.*/
