class Solution {
public:
    string convert(string s, int numRows) {
	    if (numRows  == 1)
            return s;
        int pattern = 2*(numRows - 1);
        string res;
        for (int i = 0; i < s.length(); i += pattern)
            res += s[i];
        for (int row = 1; row < numRows - 1; ++row) {
            for (int i = row; i < s.length(); i += pattern){
                res += s[i];
                if  (i + pattern - 2*row < s.length()) //in range
                    res += s[i + pattern - 2*row];
            }
        }
        for (int i = numRows - 1; i < s.length(); i += pattern)
            res += s[i];

        return res;
    }
};
