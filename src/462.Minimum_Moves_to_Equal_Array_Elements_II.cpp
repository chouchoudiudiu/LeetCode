class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int move = 0;
        nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
        int median = nums[nums.size()/2];
        for(auto v : nums) {
            move += abs(v - median);
        }
        return move;
    }
};


class Solution {
public:
////find median
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();
        int median = n%2 ? nums[n/2] : (nums[n/2] + nums[n/2 - 1])/2;
        for (auto v : nums) {
            res += abs(v - median);
        }
        return res;
    }
};

//odd, even; maybe we can find median without sort; i.e. quickselect
