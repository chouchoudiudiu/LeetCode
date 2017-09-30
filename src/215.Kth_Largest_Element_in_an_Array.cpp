class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        random_shuffle(nums.begin(), nums.end());
        int left = 0, right = n - 1;
        while (true) {
            int pos = helper (nums, left, right);
            if (pos == k - 1) 
                return nums[pos];
            if (pos > k - 1)
                right = pos - 1;
            else 
                left = pos + 1;
        }
    }
    
    int helper(vector<int>& nums, int left, int right) {
         int pivot = nums[left];
         int l = left + 1, r = right;
         while (l <= r) {
             if (nums[l] < pivot && nums[r] > pivot)
                swap(nums[l++], nums[r--]);
             if (nums[l] >= pivot)
                ++l;
             if (nums[r] <= pivot)
                --r;
         }
         swap(nums[left], nums[r]);
         return r;
    }
};
//第k大，不是kth smallest,可以再做最小的k
//r 左边所有的数字一定都大于等于pivot, 交换之后r的位置是Pivot的值 [5,5,5,5,7,6,1,2] r = 

////////////////////////////////////////////////////
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        while (--k > 0)
            pq.pop();
        return pq.top();
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto v : nums) {
            if(pq.size() < k)
                pq.push(v);
            else {
                if(pq.top() < v) {
                    pq.pop();
                    pq.push(v);
                }
            }
        }
        return pq.top();
    }
};
//use heap
