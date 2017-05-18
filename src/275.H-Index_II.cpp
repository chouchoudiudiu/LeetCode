class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0, high = n - 1;
        while (low <= high) {//出来时low > high, low更靠右，找不到刚好等于的，只能找靠右的
            int mid = low + (high - low)/2;
            if (citations[mid] < n - mid) //从右往左找到第一个citations[i] >= n - i的
                low = mid + 1;
            else if (citations[mid] > n - mid) //keep trying to move left
                high = mid - 1;
            else//==
                return n - mid; //无法再往左，左边数变小，而n - i增加
        }
        return n - low;
    }
};
