class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int l = 0, r = nums.size() - 1, minV = INT_MAX, maxV = INT_MIN;
        while(l < r && nums[l] <= nums[l + 1])
            ++l;
        if(l >= r)
            return 0;
        while(r >= 1 && nums[r] >= nums[r - 1]) 
            --r;
        for(int i = l; i <= r; ++i) {
            minV = min(minV, nums[i]);
            maxV = max(maxV, nums[i]);
        }
        while(l >= 0 && nums[l] > minV)
            --l;
        while(r <= nums.size() - 1 && nums[r] < maxV)
            ++r; //若是等就不外扩
        return r - l - 1;
    }
};
//[2,6,4,8,10,9,15]
//find min and max; two pass
//can do one pass
//[1,2,3,4]

//naive solution, sort the array and compare
