class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        vector<int> res;
        for (auto v : nums)
            x ^= v; //xor of the two numbers
        int first_diff_idx = 0;
        for (int i = 0; i < 32; ++i) {
            if ((x >> i) & 1) {
                first_diff_idx = i;
                break;
            }
        }
        int x1 = 0, x2 = 0; //partition into two sets
        for (int i = 0; i < nums.size(); ++i) {
            if ((nums[i] >> first_diff_idx) & 1)
                x1 ^= nums[i];
            else
                x2 ^= nums[i];
        }
        res.push_back(x1);
        res.push_back(x2);
        return res;
    }
};//找到两个数字异或后第一个不相同的位置，以这个位置分两边，所有该位为1和所有该位为0的数字，可以保证相同的数字一定被分到一边，而这两个数字被拆分到两边
