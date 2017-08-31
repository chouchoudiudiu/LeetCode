class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        if(n <= 2)
            return 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; ++i) {
            int j = i + 1, k = n - 1; 
            while(j < k) {
                while(j < k && nums[i] + nums[j] <= nums[k]) 
                    --k;
                if(j < k)
                    cnt += k - j;
                j = j + 1;
                k = n - 1;
            }
        }
        return cnt;
    }
};
//[1,1,3,4]
//sorted
//a b c = need to find the first b that makes a + b > c
//we already have b + c > a for sure; a + c > b for sure
//try to fix a, fix b, move k; increment b, move k, 
//move a, repeat
//[2,2,3,4]
