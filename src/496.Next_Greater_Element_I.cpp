class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        stack<int> stk;
        unordered_map<int, int> m; //in array 2, 每个数字右边第一个比它大的数的值
        for (auto v : nums) {
            while (!stk.empty() && v > stk.top()) {
                m[stk.top()] = v;
                stk.pop();
            }
            stk.push(v);
        }//已处理，可能有好几个都可以满足的，比如 7 3 1 4 2 8 碰到4 解决了3,1 碰到8 解决7 4 2
        
        for (auto v : findNums) 
            res.push_back(m.count(v) ? m[v] : -1);
        return res;
    }
};
