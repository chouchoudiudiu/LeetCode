class Solution {
public: //greedy, 1st cond otherwise get larger always, end becomes 0
    vector<int> maxNumSubArray(const vector<int>& nums, int len) {//从num中选出能构成值最大的len个数字
        vector<int> res(len, 0);
        int n = nums.size();
        for (int i = 0, j = 0; i < n; ++i) { //j + n - i, j是已经取的数字的个数；如果已经小等于了，就不可以再Pop了
            while ( j + n - i > len && j >= 1 && nums[i] > res[j - 1])//j - 1是最后一个加入的数字的index,因为之前已经入过res, j++了，
                --j; //need to be replaced, greedy, find the first biggest, and so on
            if (j < len)
                res[j++] = nums[i];
        }
        return res;
    }
    
    bool greater(const vector<int> & a, int i, const vector<int> &b, int j) {//mainly for if (!greater(res, 0, merged, 0))
        while (i < a.size() && j < b.size()) {
            if (a[i] > b[j]) return true;
            if (a[i] < b[j]) return false;
            ++i;
            ++j;
        }
        return i != a.size(); //if a reaches end while b is not, a is smaller; otherwise a is larger
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> res(k, 0);
        for (int i = max(0, k - n); i <= min(m, k); ++i) { //i <= min(m, k) i is length of first num, not index
            vector<int> res1 = maxNumSubArray(nums1, i);
            vector<int> res2 = maxNumSubArray(nums2, k - i);
            vector<int> merged(k, 0);
            int pos1 = 0, pos2 = 0, pos = 0;
            while (pos1 < res1.size() || pos2 < res2.size()) {
                merged[pos++] = greater(res1, pos1, res2, pos2) ? res1[pos1++] : res2[pos2++];
            }
            if (!greater(res, 0, merged, 0))
                res = merged;
        }
        return res;
    }
};
