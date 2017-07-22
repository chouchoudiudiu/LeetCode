class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int maxLen = 0;
        string res;
        for(auto dict : d) {
            int i = 0, j = 0, n = dict.length();
            while(i < s.length() && j < n) {
                if(s[i] == dict[j]) {
                    ++i;
                    ++j;
                }
                else
                    ++i;
            }
            if(j == n) {
                if(n >= maxLen) {
                    if(maxLen == n) 
                        res = dict < res ? dict : res;
                    else 
                        res = dict;
                    maxLen = n;
                }
            }
        }
        return res;
    }
};

//goal Time Complexity: O(nk), where n is the length of string s and k is the number of words in the dictionary.
