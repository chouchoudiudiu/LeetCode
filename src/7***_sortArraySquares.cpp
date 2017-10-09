void sortSquares(vector<int>& nums, vector<int>& sorted) {
    size_t i = 0, j = nums.size() - 1;
    while(i < j) {
        if(nums[i]*nums[i] < nums[j]*nums[j]) {
            sorted.push_back(nums[j]*nums[j]);
            --j;
        }
        else {
            sorted.push_back(nums[i]*nums[i]);
            ++i;
        }
    }
    sorted.push_back(nums[i]*nums[i]);
}
