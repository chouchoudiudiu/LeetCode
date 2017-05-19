class Solution {
public: 
    int minPatches(vector<int>& nums, int n) {
        int patch = 0, i = 0, next = 1;
        long sum = 0;
        while (sum < n) {
            if (i < nums.size() && nums[i] <= next) {//nums[i] <= next, otherwise miss next, need to patch next
                sum += nums[i++]; //sum is the range you could cover
            }
            else {
                sum += next; //the number to be patched;
                ++patch;
            }
            next = sum + 1;
        }
        return patch;
    }
};

//greedy
