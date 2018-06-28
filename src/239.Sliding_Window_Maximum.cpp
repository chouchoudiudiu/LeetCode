class Solution {
public:
//Remove redundant elements and the queue should store only elements that need to be considered.
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty())
            return {};
        vector<int> res;
        deque<int> dq; //index
        for (int i = 0; i < k; ++i) {
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        for(int i = k; i < nums.size(); ++i) {
            res.push_back(nums[dq.front()]);
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i - dq.front() >= k) //may or may not in good window, if not, retire
                dq.pop_front();
        }
        res.push_back(nums[dq.front()]);
        return res;
    }
};
