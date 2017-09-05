class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        for (int i = 0; i < n; ++i) {
            if (citations[i] >= n - i) //该数之后含该数共有n-i个数，说明这n-i个数都满足citation数超过citation[i]
                return n - i; //如果一早遇到一到一个citation小于n - i说明后面有更大的，要刚刚好
        }
        return 0;
    }
};

//or do it in the other direction
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size(), i = 0;
        for(i = n - 1; i >= 0; --i) {
            if(citations[i] < n - i)
                return n - i - 1;
        }
        return n - i - 1;
    }
};
