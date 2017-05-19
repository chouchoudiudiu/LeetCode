class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) { //dp
        if (triangle.empty())
            return 0;
        int n = triangle.size();
        vector<int> m(n);
        for (int i = 0; i < n; ++i) 
            m[i] = triangle[n - 1][i];

        //每一个m[j]等于其两个孩子m值中较小的一个加上自身的值。    
        for (int i = n - 2; i >= 0; --i) 
            for (int j = 0; j <= i; ++j) 
                m[j] = triangle[i][j] + min(m[j], m[j + 1]); //m[j]
 
        return m[0];
    }
};
