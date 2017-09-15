class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        for(int i = 0; i < k; ++i)
            res.push_back(arr[i]);
        for(int i = k; i < arr.size(); ++i) {
            if(abs(arr[i] - x) < abs(res[0] - x)) {
                res.erase(res.begin());
                res.push_back(arr[i]);
            }
            else if(abs(arr[i] - x) > abs(res[0] - x))
                break;
        }
        return res;
    }
};
//////////
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int i = idx - 1, j = idx;
        while(k--) {
            if(i < 0 || (j < arr.size() && abs(arr[i] - x) > abs(arr[j] - x)))
                ++j;
            else
                --i;
        }
        return vector<int>(arr.begin() + i + 1, arr.begin() + j);
    }
};

/*
The idea is to find the first number which is equal to or greater than x in arr. Then, we determine the indices of the start and the end of a subarray in arr, where the subarray is our result. The time complexity is O(logn + k).

In the following code, arr[index] is the first number which is euqal to or geater than x (if all numbers are less than x, index is arr.size()), and the result is arr[i+1, i+2, ... j].
*/
