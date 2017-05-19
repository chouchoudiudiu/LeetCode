class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long> sets; //multiset permits duplicate keys, sorted
        long long sum = 0;
        int res = 0;
        sets.insert(0); //necessary!!
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            res += distance(sets.lower_bound(sum - upper), sets.upper_bound(sum - lower));
            sets.insert(sum);
        }
        
        return res;
    }
};

//was using mergesort
//sum[i] - upper =< sum[j] <= sum[i] - lower
