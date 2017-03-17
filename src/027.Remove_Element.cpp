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

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
//What happens when the elements to remove are rare?
        int i = 0;
        int j = nums.size();

        while (i < j) {
            if (nums[i] == val) {
                while (--j > i && nums[j] == val); //find the first j from right that is not val
                if (i >= j) //up to i are all non-val, 2333; return 1 when 23 are left
                    break;
                else
                    nums[i] = nums[j]; //no need to swap
            }
            ++i;
        }
        nums.resize(i); //optional
        return i;
    }
};

