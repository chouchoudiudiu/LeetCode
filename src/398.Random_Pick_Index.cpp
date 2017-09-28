 //reservior sampling
class Solution {
public:
    Solution(vector<int> nums): v(nums) {
        
    }
    
    int pick(int target) {
        int res = -1, cnt = 0;
        for(int i = 0; i < v.size(); ++i) {
            if(v[i] != target)
                continue;
            ++cnt;
            if(rand()%cnt == 0)
                res = i;
        }
        return res;
    }
    
    vector<int> v;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
/*
我们定义两个变量，计数器cnt和返回结果res，我们遍历整个数组，如果数组的值不等于target，直接跳过；
如果等于target，计数器加1，然后我们在[0,cnt)范围内随机生成一个数字，如果这个数字是0，我们将res赋值为i即可
*/

