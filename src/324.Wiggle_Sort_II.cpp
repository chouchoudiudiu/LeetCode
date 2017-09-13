class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int n = nums.size(), j = n, k = n/2 + n%2; //1122 334
        for(int i = 0; i < n; ++i){//insert one by one
            nums[i] = (i & 1) ? sorted[--j]:sorted[--k];
        }
    }
};
//[4,5,5,6] 分开错开取, 如果顺序取, 4(3) 5(1) 5(4) 6(2), 否则接近的值可能凑在一起 4556l same for 112223;
//if use wigglesort 1 [1,2,2,1,2,1,1,1,1,2,2,2]
//sort and swap [1, 3, 2, 2, 3, 1]
//4 5 5 6 1 得到 5 6 4 5 1
//还没看O(N)的做法
