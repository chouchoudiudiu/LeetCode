class Solution {
public:
//greedy 只要找到第一个就可以
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                ++i;
                ++j;
            }
            else
                ++j;
            if (i == s.length())
                return true;
        }
        return i == s.length();
    }
};

/*Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> m(26);
        //add indexes of each chars in t
        for(int i = 0; i < t.size(); ++i)
            m[t[i] - 'a'].push_back(i);
        //check if each char in s is in legal place
        int idx = 0;
        for(int i = 0; i < s.size(); ++i) {
            int c = s[i] - 'a';
            auto iter = lower_bound(m[c].begin(), m[c].end(), idx);
            if(iter == m[c].end())
                return false;
            idx = *iter + 1;
        }
        return true;
    }
};

/* slogt
For follow-up. Trade space for time. Store char positions for t.
s = aabac,
t = aaabaac.
{a: [0,1,2,4,5],
b: [3],
c: [6]}
Initialize lowerBound = 0. Iterate over s, binary search the first position of the current char satisfying position >= lowerBound, update lowerBound with the found position + 1.
 * Follow-up
 * If we check each sk in this way, then it would be O(kn) time where k is the number of s and t is the length of t. 
 * This is inefficient. 
 * Since there is a lot of s, it would be reasonable to preprocess t to generate something that is easy to search for if a character of s is in t. 
 * Sounds like a HashMap, which is super suitable for search for existing stuff. 
*/
