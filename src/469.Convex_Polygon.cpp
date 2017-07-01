class Solution {
public:
// For each set of three adjacent points A, B, C, find the cross product AB · BC. If the sign of
        // all the cross products is the same, the angles are all positive or negative (depending on the
        // order in which we visit them) so the polygon is convex.
    bool isConvex(vector<vector<int>>& points) {
        long long prev = 0, curr = 0, n = points.size();
        for (int A = 0; A < n; ++A) {
            int B = (A + 1)%n;
            int C = (A + 2)%n;
            int BAx = points[B][0] - points[A][0];
            int BAy = points[B][1] - points[A][1];
            int BCx = points[B][0] - points[C][0];
            int BCy = points[B][1] - points[C][1];
            curr = BAx*BCy - BAy*BCx; //uxv	=	det(uv)	=	u_xv_y-u_yv_x
            if (curr != 0)  { //http://csharphelper.com/blog/2014/07/determine-whether-a-polygon-is-convex-in-c/
                 if(curr*prev < 0) //need to be always in same direction
                    return false;
                prev = curr;
            }
        }
        
        return true;
    }
};

//http://mathworld.wolfram.com/CrossProduct.html
//http://csharphelper.com/blog/2014/07/determine-whether-a-polygon-is-convex-in-c/
这里我们要特别注意法向量为0的情况，如果某一个点的法向量算出来为0，那么正确的pre就会被覆盖为0，
后面再遇到相反的法向就无法检测出来，所以我们对计算出来法向量为0的情况直接跳过即可
