class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> m; //sum, cnt
        int N = A.size(), cnt = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j) {
                int sum = A[i] + B[j];
                m[sum]++;
            }
        
        for (int k = 0; k < N; ++k)
            for (int l = 0; l < N; ++l) {
                int sum = C[k] + D[l];
                if (m.count(-sum))
                    cnt += m[-sum];
            }    
        
        return cnt;
    }
};

//某两组的和，该和的count，最终函数只需要返回个数
