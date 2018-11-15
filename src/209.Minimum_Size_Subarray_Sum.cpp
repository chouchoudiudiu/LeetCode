class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;
        int minLen = INT_MAX, sum = 0; 
        bool found = false;
        for (int start = 0, end = 0; end < nums.size();) {
            sum += nums[end++];
            while (sum >= s) {
                minLen = min(minLen, end - start); //end already ++
                if (minLen == 1) return 1;//can't be shorter
                sum -= nums[start++];
                found = true;
            }
        }
        return found ? minLen : 0;
    }
};

/*
More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minLen = INT_MAX, sum = 0;
        for(int start = 0, end = 0; end < nums.size(); ++end) {
            sum += nums[end];
            while(sum >= s) {
                minLen = min(minLen, end - start + 1);
                sum -= nums[start++];
            }
        }
        return minLen == INT_MAX ? 0:minLen;
    }
};

//sliding window? two pointers
