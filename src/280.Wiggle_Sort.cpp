class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {//every two
            if ( (i%2 == 0 && nums[i] > nums[i - 1]) || (i%2 == 1 && nums[i] < nums[i - 1]))//互换之后大小放大
                swap(nums[i], nums[i - 1]);
        }
    }
};
