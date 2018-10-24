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

//////
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty())
            return 0;
        int n = triangle.size();
        vector<int> m = triangle.back(); //last line
        for(int i = n - 2; i >= 0; --i) 
            for(int j = 0; j <= i; ++j)  //算下个j的时候，不需要用到旧的j，一直是往大的走的，所以不需要一个tmp
                m[j] = min(m[j], m[j + 1]) + triangle[i][j];   
        return m[0];
    }
};
