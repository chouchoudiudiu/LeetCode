class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cum = 0, cnt = 0;
        unordered_map<int, int> m; //prefix sum, cnt
        m[0] = 1;
        for(int i = 0; i < nums.size(); ++i) {
            cum += nums[i];
            cnt += m[cum - k]; //not k - cum!
            m[cum]++;
        }
        return cnt;
    }
};


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> un_map; //prefix sum, count
        int cnt = 0, sum = 0;
        un_map[0] = 1;
        for(size_t i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if(un_map.count(sum - k))
                cnt += un_map[sum - k];
            un_map[sum]++;
        }
        return cnt;
    }
};
