class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                    ++j;
                else if (sum > 0)
                    --k;
                else {
                        res.insert({nums[i], nums[j], nums[k]});
                        ++j;
                        --k;
                }
            }
        }
        
        return vector<vector<int>>(res.begin(), res.end()); //easy convert from set to vector
    }
};

/* //not using set
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                    ++j;
                else if (sum > 0)
                    --k;
                else {
                        res.push_back({nums[i], nums[j], nums[k]});
                        ++j;
                        while (j < k && nums[j] == nums[j - 1]) //skipping duplicates
                            ++j;
                        --k;
                        while (j < k && nums[k + 1] == nums[k]) //skipping duplicates
                            --k;
                }
            }
        }
        
        return res;
    }
};
*/
