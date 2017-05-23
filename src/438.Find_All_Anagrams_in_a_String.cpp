class Solution {
public:
//sliding window
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int sLen = s.length(), pLen = p.length();
        int needToFind[26] = {0};
        for (auto c : p) 
            needToFind[c - 'a']++;
        int i = 0, j = 0, cnt = 0; 
        while (i < sLen) { //i: end, j: start
            if (needToFind[s[i++] - 'a']-- >= 1) //those not in needtofind, will decrease all the time
                cnt++;
            if (cnt == pLen)
                res.push_back(j);
            if (i - j == pLen && needToFind[s[j++] - 'a']++ >= 0) //>=, not enough
                cnt--;
        }
        return res;
    }
};
//从第一次满足pLen之后就一直满足 end - begin == pLen，是一个框定
//若sliding window长度达到，需要调整begin,如果这个字母是需要的，count--,如果不是，不用减少count
