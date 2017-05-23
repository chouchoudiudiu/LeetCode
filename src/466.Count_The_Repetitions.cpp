class Solution {
public:
/** DP...hard....
 * Assume that s2 is self-repeating forever, i.e., s2s2s2s2s2...
 * Let f[i] be the maximum number of letters of s2 (in self-repeating mode) that i copies of s1 can match.
 * The final answer will be floor(f[n1] / (|s2| * n2)).     f[n1] / (s2.length() * n2); */
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        string s2Padded = s2;
        while (s2Padded.length() < s1.length())
            s2Padded += s2;
        s2Padded += s2; //backup
        
        vector<int> matchFrom(s2Padded.length(), 0);
        for (int beginIndex = 0; beginIndex < matchFrom.size(); ++beginIndex) {
            string a = s1;
            string b = s2Padded.substr(beginIndex);
            int i = 0, j = 0;
            while (i < a.length() && j < b.length()) {
                if (a[i] == b[j]) {
                    ++i;
                    ++j;
                }
                else
                    ++i;
            }
            matchFrom[beginIndex] = j;
        }
        
        vector<int> f(n1 + 1, 0);
        for (int i = 1; i < f.size(); ++i) {//from 1 copy to n1 copy
            int letterMatched = f[i - 1]%s2.length();
            f[i] = f[i - 1] + matchFrom[letterMatched]; //接着填
        }
        
        return f[n1]/(s2.length() * n2);
    }
};
        // matchFrom[beginIndex] is the maximum number letters of s2 (in self-repeating mode and starting from s2[beginIndex])
        // that a SINGLE copy of s1 can match.
        // This dp array can be computed in less time, but it is fine to use brute-force here
