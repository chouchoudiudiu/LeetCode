class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0, high = n - 1; 
        while(low <= high) {//出来时low > high, low更靠右，找不到刚好等于的，只能找靠右的
            int mid = low + (high - low)/2;
            if(citations[mid] >= n - mid) //从右往左找到第一个citations[i] >= n - i的
                high = mid - 1;//keep trying to move left
            else
                low = mid + 1;
        }
        return n - low;
    }
};
//无法再往左，左边数变小，而n - i增加
//citations = [3, 0, 6, 1, 5] [0, 1, 3, 5, 6]
//出来时low > high, low更靠右，找不到刚好等于的，只能找靠右的
//其实就是search insert position...
