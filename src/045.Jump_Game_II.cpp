class Solution {
public:
    int jump(vector<int>& nums) {
        //DP TLE (space?), greedy..
        /*
        二指针问题，最大覆盖区间。
        从左往右扫描，维护一个覆盖区间，每扫过一个元素，就重新计算覆盖区间的边界。比如，开始时区间[start, end], 遍历A数组的过程中，不断计算A[i]+i 最大值（即从i坐标开始最大的覆盖坐标），并设置这个最大覆盖坐标为新的end边界。而新的start边界则为原end+1。不断循环，直到end> n.
        */
        int n = nums.size();
        if (n <= 1) return 0;
        int start = 0, end = nums[0], steps = 1;
        while (end < n - 1) { //n - 1 is the end of array
            int maxPos = 0;
            for (int i = start; i <= end; ++i) {
                maxPos = max(maxPos, i + nums[i]);
            }
            start = end + 1;
            end = maxPos;
            ++steps;
        }
        
        return steps; 
    }
};
//[2,1]
