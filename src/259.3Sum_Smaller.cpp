class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int smallerCount = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum >= target) 
                    --k;
                else { //sum < target
                    smallerCount += k - j; //如果退到k(i,j,k)可以满足，则一直到最后一个(i, j, j+1)都可以满足
                    ++j; //k will keep shinking
                }
            }
        }
        return smallerCount;
    }
};
