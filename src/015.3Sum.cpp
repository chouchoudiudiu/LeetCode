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

//变种
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> getTargetSums(vector<int>& v1, vector<int>& v2, vector<int>& v3, int target) {
    vector<vector<int>> res;
    if(v1.empty() || v2.empty() || v3.empty())
        return res;
    for(int i = 0; i < v1.size(); ++i) {
        if(i > 0 && v1[i] == v1[i - 1])
            continue;
        int j = 0, k = v3.size() - 1;
        while(j < v2.size() && k >= 0) {
            int sum = v1[i] + v2[j] + v3[k];
            if(sum < target)
                ++j;
            else if(sum > target)
                --k;
            else {
                res.push_back({v1[i], v2[j], v3[k]});
                ++j;
                while(j < v2.size() && v2[j - 1] == v2[j])
                    ++j;
                --k;
                while(k >= 0 && v3[k + 1] == v3[k])
                    --k;
            }
        }
    }
    return res;
}

int main() {
    cout<<"Hello"<<endl;
    vector<int> v1 = {-1, 2, 2, 4, 5, 6, 6, 8, 11};
    vector<int> v2 = {-4, -2, 0, 3, 3, 5, 6, 7, 10, 12};
    vector<int> v3 = {-5,0,1, 2,3,3,3,4,5,6, 7,8,9, 11};
    int target = 14;
    vector<vector<int>> res = getTargetSums(v1, v2, v3, target);
    for(auto& vec : res) {
        for(auto& v : vec) {
            cout<<v<<',';
        }
        cout<<endl;
    }
    return 0;
}
