bool isMono(vector<int>& nums) {
    bool up = true, down = true;
    size_t i = 1;
    while(i < nums.size()) {
        if(nums[i] > nums[i - 1] && up) {
            ++i;
            down = false;
        }
        else if(nums[i] < nums[i - 1] && down) {
            ++i;
            up = false;
        }
        else
            return false;
    }
    return i == nums.size();
}
