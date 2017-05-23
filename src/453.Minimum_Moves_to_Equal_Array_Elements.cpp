class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = *min_element(nums.begin(), nums.end());
        long sum = accumulate(nums.begin(), nums.end(), 0);
        return sum - min*nums.size();
    }
};

//incrementing n - 1 elements by 1 相当于每次选一个数字减1，将所有数字减到一样小
