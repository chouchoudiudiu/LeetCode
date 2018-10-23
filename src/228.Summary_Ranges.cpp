class Solution {
public:
    string rangeToString(int lower, int upper) {
        if(lower == upper)
            return to_string(lower);
        else
            return to_string(lower) + "->" + to_string(upper); //"", more than 1 char
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        if (n == 0)
            return res;
        int last = nums[0];
        for (int i = 1; i < n; ++i) {
            if ((long long)nums[i] - (long long)nums[i - 1] > 1) {// a new start....over flow (long, long)
                res.push_back(rangeToString(last, nums[i - 1]));
                last = nums[i];
            }
        }
        //special process for last one
        res.push_back(rangeToString(last, nums[n - 1])); //continuous
        return res;
    }
};

//[-2147483648,-2147483647,2147483647]
==========
    
    class Solution {
public:
    string helper(int start, int end, vector<int>& nums) {
        if(start == end)
            return to_string(nums[start]);
        else
            return to_string(nums[start]) + "->" + to_string(nums[end]);
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.empty())
            return res;
        int start = 0, end = 0;
        if(nums.size() == 1)
            return {helper(start, end, nums)};
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == nums[i - 1] + 1)
                ++end;
            else {
                res.push_back(helper(start, end, nums));
                start = end = i;
            }
        }
        res.push_back(helper(start, end, nums));
        return res;
    }
};
