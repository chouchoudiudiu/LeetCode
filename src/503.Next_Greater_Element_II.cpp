class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> stk; //keep the indexes of the decreasing subsequence
        for(int i = 0; i < 2*n; ++i) {
            int num = nums[i%n];
            while(!stk.empty() && num > nums[stk.top()]) {
                res[stk.top()] = num;
                stk.pop();
            }
            if(i < n)
                stk.push(i);
        }
        return res;
    }
};
