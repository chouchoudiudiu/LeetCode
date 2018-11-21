class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return canWin(nums, 0, 0, 1);
    }
    
    bool canWin(vector<int>& nums, int sum1, int sum2, int player) {//whether a player can win
        if (nums.empty())
            return sum1 >= sum2;
        if (nums.size() == 1) {
            if (player == 1)
                return sum1 + nums[0] >= sum2;
            if (player == 2)
                return sum2 + nums[0] > sum1; //how player2 can win
        }
        else {
            vector<int> va(nums.begin() + 1, nums.end());
            vector<int> vb(nums.begin(), nums.end() - 1);
            if (player == 1) //player1 选择了nums[0] or last one
                return !canWin(va, sum1 + nums[0], sum2, 2) || !canWin(vb, sum1 + nums.back(), sum2, 2);
            if (player == 2) //player2 选择了nums[0] or last one
                return !canWin(va, sum1, sum2 + nums[0], 1) || !canWin(vb, sum1, sum2 + nums.back(), 1);
        }
    }
};


////
        if(nums.empty()) {
            if(player == 1)
                return sum1 >= sum2;
            if(player == 2)
                return sum2 > sum1;
        }
