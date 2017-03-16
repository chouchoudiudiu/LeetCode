class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) 
                nums[j++] = nums[i];
        }
        nums.resize(j);
        return j;
    }
};

//need to think: What happens when the elements to remove are rare?
//https://leetcode.com/articles/remove-element/#approach-2-two-pointers-when-elements-to-remove-are-rare-accepted
