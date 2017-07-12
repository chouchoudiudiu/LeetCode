class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m; //sum%k, index
        int sum = 0;
        m[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int t = (k == 0) ? sum : (sum%k);
            if (m.count(t)) { 
                if (i - m[t] >= 2)
                    return true;
            }
            else //first appearance
                m[t] = i;
        }
        return false;
    }
};

//23 2 4 6 每一个结尾为sum%k, 到新数，得到当前sum，再%k，看看之前是否已经有得到过这个值，若有，说明中间有一段%k=0

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m; //sum, idx
        int sum = 0;
        m[0] = -1;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            for(auto v : m) {
                if(i - v.second >= 2) {
                   if((sum == v.first && k == 0 ) || (k != 0 && (sum - v.first)%k == 0))
                        return true;
                }
            }
            if(m.find(sum) == m.end())
                m[sum] = i; //first appearance
        }
        return false;
    }
};
/*
[23,2,6,4,7]
0
*/
