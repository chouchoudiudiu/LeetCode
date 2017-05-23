class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0, cnt = 0;
        for (auto v : nums) {
            if (v == 1) 
                max = max > ++cnt ? max : cnt;
            else
                cnt = 0; //meet 0, reset the 1 counter
        }
        
        return max;
    }
};
/////////////////////////////////////////////////////////////
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        bool inCount = false;
        int maxOnes = 0, j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (inCount && nums[i] == 0) {
                maxOnes = max(maxOnes, i - j);
                inCount = false;
            }
            if (!inCount && nums[i] == 1) {
                inCount = true;
                j = i; //first 1 in new calculate
            }
        }
        if (inCount) 
            maxOnes = max(maxOnes, (int)nums.size() - j);

        return maxOnes;
    }
};
