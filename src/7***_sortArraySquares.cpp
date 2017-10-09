void sortSquares(vector<int>& nums, vector<int>& sorted) {
    size_t l = 0, r = nums.size() - 1, idx = r;
    for(size_t i = 0; i < nums.size(); ++i) {
        if(abs(nums[l]) < abs(nums[r])) {
            sorted[idx--] = nums[r]*nums[r];
            --r;
        }
        else {
            sorted[idx--] = nums[l]*nums[l];
            ++l;
        }
    }
}

///////////////////////////////////////////////////////////////////
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
