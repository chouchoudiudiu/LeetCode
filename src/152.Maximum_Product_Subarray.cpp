class Solution {
public:
/*
max_product[i] = max(max_product[i-1]*A[i], min_product[i-1]*A[i], A[i]) 
min_product[i] = min(max_product[i-1]*A[i], min_product[i-1]*A[i], A[i]) 
*/
    int maxProduct(vector<int>& nums) {
        if (nums.empty())    
            return 0;
        int maxProduct = nums[0];
        int localMin = nums[0];
        int localMax = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int tmp1 = localMin*nums[i];
            int tmp2 = localMax*nums[i];
            localMin = min(min(tmp1, tmp2), nums[i]);
            localMax = max(max(tmp1, tmp2), nums[i]);
            maxProduct = max(maxProduct, localMax);
        }
        return maxProduct;
    }
};

/*
简单粗暴，就是找出所有的子数组，然后算出每一个子数组的乘积，然后比较找出最大的一个，需要两个for循环，第一个for遍历整个数组，
第二个for遍历含有当前数字的子数组，就是按以下顺序找出子数组: [2], [2, 3], [2, 3, -2], [2, 3, -2, 4], [3], [3, -2], [3, -2, 4], 
    [-2], [-2, 4], [4]
第二次优化，其实子数组乘积最大值的可能性为：累乘的最大值碰到了一个正数；或者，累乘的最小值（负数），碰到了一个负数。所以每次要保存累乘的最大（正数）和最小值（负数）。同时还有一个选择起点的逻辑，如果之前的最大和最小值同当前元素相乘之后，没有当前元素大（或小）那么当前元素就可作为新的起点。例如，前一个元素为0的情况，{1,0,9,2}，到9的时候9应该作为一个最大值，也就是新的起点，{1,0,-9,-2}也是同样道理，-9比当前最小值还小，所以更新为当前最小值。
这种方法只需要遍历一次数组即可，算法时间复杂度为O(n)。
*/
