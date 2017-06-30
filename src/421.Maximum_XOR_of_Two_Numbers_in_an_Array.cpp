class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = 0, mask = 0;
        for (int i = 31; i >= 0; --i) {
            mask = mask | (1<<i); //mask作为前缀比如 110000, 100000
            unordered_set<int> set; 
            for (auto v : nums) 
                set.insert(mask & v); //0 is always in set
            int tmp = max | (1<<i); //仅该位为1，加上之前的max(之前已经为1的)
            for (auto pre : set) {
                if (set.find(tmp ^ pre) != set.end()) { //11000 tmp 遇到00100 mask&v
                    max = tmp; //若a^b=c，那么a=b^c
                    break; //并不是第一个找到的就是最大的？
                }
            }
        }
        return max;
    }
};

/*
题目中给定了数字的返回不会超过231,那么最多只能有32位，我们用一个从左往右的mask，用来提取数字的前缀，然后将其都存入set中，我们用一个变量t，
用来验证当前位为1再或上之前结果res，看结果和set中的前缀异或之后在不在set中，这里用到了一个性质，若a^b=c，那么a=b^c，因为t是我们要验证的当前最大值，
所以我们遍历set中的数时，和t异或后的结果仍在set中，说明[两个前缀可以异或出t的值]，所以我们更新res为t，继续遍历
*/
