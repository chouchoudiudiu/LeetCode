class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string res;
        if(nums.empty())
            return res;
        if(nums.size() == 1)
            return to_string(nums[0]);
        if(nums.size() == 2)
            return to_string(nums[0]) + '/' + to_string(nums[1]);
        res = to_string(nums[0]) + "/(";
        for(int i = 1; i < nums.size(); ++i)
            res += to_string(nums[i]) + '/';
        res.pop_back();
        return res + ')'; //"" also fine
    }
};
/*
X1/X2/X3/../Xn will always be equal to (X1/X2) * Y, no matter how you place parentheses. i.e no matter how you place parentheses, X1 always goes to the numerator and X2 always goes to the denominator. Hence you just need to maximize Y. And Y is maximized when it is equal to X3 *..*Xn. So the answer is always X1/(X2/X3/../Xn) =       (X1 *X3 *..*Xn)/X2
*/
