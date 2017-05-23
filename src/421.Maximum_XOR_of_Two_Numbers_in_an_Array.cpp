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
