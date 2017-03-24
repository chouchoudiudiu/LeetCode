class Solution {
public:
    int getMin(int a, int b, int c) {
        int less = min (a, b);
        return min(less, c);
    }
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        int d[m + 1][n + 1] = {0};
        for (int i = 0; i <= m; ++i) //delete one by one
            d[i][0] = i;
        for (int j = 0; j <= n; ++j)
            d[0][j] = j; //insert one by one
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j) {
                int rCost = (word1[i - 1] == word2[j - 1]) ? 0 : 1;
                d[i][j] = getMin(d[i][j - 1] + 1, d[i - 1][j] + 1, d[i - 1][j - 1] + rCost); 
                //insert word2[j - 1], delete word1[i - 1], replace word1[i - 1] by word2[j - 1]
            }
        return d[m][n];
    }
};

//can reduce memory to O(N)
