class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        //测试从0到mid的每个子串
        int n = s.length();
        for (int i = 1; i <= n/2; ++i) { //length
            string p = s.substr(0, i);
            int j = i; 
            for (; j <= n - i; j += i) {
                string p2 = s.substr(j, i);
                if (p != p2)
                    break;
            }
            if (j >= n)
                return true;
        }
        return false;
    }
};
