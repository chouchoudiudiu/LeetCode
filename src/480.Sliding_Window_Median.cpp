class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<int> small, large;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                if (small.count(nums[i - k]))  //finds returns the first location of the key; small usually has one more item
                    small.erase(small.find(nums[i - k]));
                else if (large.count(nums[i - k])) //else if, not if!
                    large.erase(large.find(nums[i - k]));
            }
            
            if (small.size() <= large.size()) { //<=, not ==
                if (!small.empty() && nums[i] > *large.begin()) {
                    small.insert(*large.begin());
                    large.erase(large.begin());
                    large.insert(nums[i]);
                }
                else
                    small.insert(nums[i]);
            }
            else {
                if (nums[i] > *small.rbegin())
                    large.insert(nums[i]);
                else {
                    large.insert(*small.rbegin());
                    small.erase(--small.end()); //past 1 element
                    small.insert(nums[i]);
                }
            }
 
            // If window is full, get the median from 2 multisets.
            if (i >= (k - 1)) {
                if (k % 2) 
                    res.push_back(*small.rbegin());
                else 
                    res.push_back( (double(*small.rbegin()) + double(*large.begin())) / 2.0);
            } 
        }
        return res;
    }
};
//[2147483647,1,2,3,4,5,6,7,2147483647]
//2
