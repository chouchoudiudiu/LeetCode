class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int res = 0;
        for(auto v : nums)
            ++m[v];
        for(auto a : m) {
            if(k == 0 && a.second > 1)
                ++res;
            if(k > 0 && m.count(a.first + k))
                ++res;
        }
        return res;
    }
};

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        sort(nums.begin(), nums.end());
        int cnt = 0, i = 0, n = nums.size(), j = n - 1;
        while (i <= j) { //to enter else! very important
            if (nums[j] - nums[i] > k)
                --j;
            else { //== <可忽略
                if(i != j && nums[j] - nums[i] == k)
                    ++cnt;
                while (i < n - 1 && nums[i] == nums[i + 1])
                    ++i;
                ++i;
                j = n - 1;
            }
        }
        return cnt;
    }
};
/*
[6,2,9,3,9,6,7,7,6,4]
3

<= 这样 i和j可以reset成i是下一个和之前i不相等的数字，j是回到n-1
*/
