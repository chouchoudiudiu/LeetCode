class Solution {
public:
    int lengthLongestPath(string input) {
        vector<string> tokens = getTokens(input);
        int n = tokens.size();
        vector<int> lens(n + 1, 0); //more than necessary...this is the maxsize of lens depth
        int maxLen = 0;
        for (auto v : tokens) {
            auto pos = v.find_last_of('\t'); // \tSubstr1 returns 0
            int level = (pos == string::npos) ?  0 : pos + 1;
            if (v.find('.') == string::npos) {
                if (level == 0)
                    lens[level] = v.size();
                else
                    lens[level] = lens[level - 1] + v.size() - level; //v.size() - level is actual char size
            }
            else {
                if (level == 0)
                    maxLen = max(maxLen, (int)v.size());
                else
                    maxLen = max(maxLen, lens[level - 1] + (int)v.size());// /t replaced by / in absolute path (2)
            }
        }
        return maxLen;
    }//从subdir1到subdir2遍历过程中lens的值都改变了
    
    vector<string> getTokens(string input) {
        vector<string> res;
        istringstream iss(input);
        string s;
        while(getline(iss, s, '\n')) {
            res.push_back(s);
        }
        return res;
    }
};
