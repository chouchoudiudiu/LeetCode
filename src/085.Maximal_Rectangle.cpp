class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
	        return 0;
        int m = matrix.size(), n = matrix[0].size(), maxArea = 0;
        vector<int> heights(n);

        for (int i = 0; i < m; ++i) {
	        for (int j = 0; j < n; ++j) {
		        if (matrix[i][j] == '0')
			        heights[j] = 0;
		        else
			        heights[j]++;	
	        }
	        maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        stk.push(-1);
        int n = heights.size();
        int maxArea = 0;
        vector<int> width(n, 0);
        for (int i = 0; i < n; ++i) {
            while(!stk.empty() && stk.top() >= 0 && heights[i] <= heights[stk.top()])
                stk.pop();
            width[i] = i - stk.top() - 1;
            stk.push(i);
        }
        stk = stack<int>();
        stk.push(n);
        for (int i = n - 1; i >= 0; --i) {
            while(!stk.empty() && stk.top() <= n - 1 && heights[i] <= heights[stk.top()])
                stk.pop();
            width[i] += stk.top() - i;
            stk.push(i);
        }
        
        for (int i = 0; i < n; ++i) {
            maxArea = max(maxArea, heights[i]*width[i]);
        }
        
        return maxArea;
    }
};
