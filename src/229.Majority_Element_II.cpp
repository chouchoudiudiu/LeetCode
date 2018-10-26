class Solution {
public:
// Moore Voting
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 0, m1 = 0, m2 = 0; 
        vector<int> res; //find the most appeared numbers, different
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == m1) 
                ++c1;
            else if (nums[i] == m2)
                ++c2;
            else if (c1 == 0) {
                m1 = nums[i];
                c1 = 1;
            }
            else if (c2 == 0) {
                m2 = nums[i];
                c2 = 1;
            }
            else {
                --c1;
                --c2;
            }
        }
        c1 = 0, c2 = 0; //get actual count of c1 and c2
        for (auto v : nums) {
            if (v == m1)
                ++c1;
            else if (v == m2)
                ++c2;
        }
        if (c1 > nums.size()/3) res.push_back(m1);
        if (c2 > nums.size()/3) res.push_back(m2);
        
        return res;
    }
};
//majority 1 中假定众数一定存在了
//需要两遍遍历，第一遍历找出两个候选众数，第二遍遍历重新投票验证这两个候选众//数是否为众数即可
//[8,8,7,7,7] 注意顺序，不是先判断c1, c2
