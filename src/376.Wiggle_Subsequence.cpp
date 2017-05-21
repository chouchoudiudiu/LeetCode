class Solution {
public: //Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. 
//greedy: ignore number that doesn't contribute
//可以改成用一个dir变量来控制方向
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty())
            return 0;
        bool up = true, down = true;//起始两个方向都可以
        int maxLen = 1; //at least 1
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1] && up) { //如目前期望下一个数比自己大，碰到了，转换状态，增加  
                up = false;
                down = true;
                ++maxLen; 
            } //若此时希望碰到比自己小的数，现在却碰到比自己大的数，继续前行，新的数因为比自己大，碰到比它小的数更加理所当然
            else if (nums[i] < nums[i - 1] && down) {
                down = false;
                up = true;
                ++maxLen;
            }
            //== continue
        }
        return maxLen;
    }
};
