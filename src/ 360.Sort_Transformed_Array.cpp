class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res(nums.size());
        int left = 0;
        int right = nums.size() - 1;
        int i = a >= 0 ? right : left;
        while (left <= right) {
            int leftVal = f(nums[left], a, b, c);
            int rightVal = f(nums[right], a, b, c);
            if (a >= 0) { //最小值在中间,最大值在两边（与b的正负无关），从大到小填（两边到中间），i从n - 1开始
                if (rightVal > leftVal) {
                    res[i--] = rightVal;
                    --right;
                }
                else {
                    res[i--] = leftVal;
                    ++left;
                }
            }
            else { //最大值在中间,从小到大填（两边到中间），i从0开始
                if (leftVal < rightVal) {
                    res[i++] = leftVal;
                    ++left;
                }
                else {
                    res[i++] = rightVal;
                    --right;
                }
            }
        }
        return res;
    }

    int f(int x, int a, int b, int c) {
        return a*x*x + b*x + c;
    }
};
