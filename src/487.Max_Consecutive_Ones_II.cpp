class Solution {
public:
//sliding window with at most k zero flip
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, zero = 0, left = 0, k = 1; //通解;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0)
                ++zero;
            while (zero > k) {
                if (nums[left++] == 0)
                    --zero;
            }
            res = max(res, right - left + 1); //维护一个窗口[left,right]来容纳至少k个0
        }
        return res;
    }
};

////////////////////////////////////////////////
class Solution {
public:
//sliding window with at most k zero flip
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, left = 0, k = 1; //通解;
        queue<int> q;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0)
                q.push(right);
            while (q.size() > k) { //q.size()
                left = q.front() + 1;
                q.pop();
            }
            res = max(res, right - left + 1); //维护一个窗口[left,right]来容纳至少k个0
        }
        return res;
    }
};

//follow up, 我们可以将遇到的0的位置全都保存下来，这样我们需要移动left的时候就知道移到哪里了
