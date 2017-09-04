class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int a = 0; a <= sqrt(c); ++a) {
            int comp = c - a*a;
            int b = sqrt(comp);
            if(a*a + b*b == c)
                return true;
        }
        return false;
    }
};
