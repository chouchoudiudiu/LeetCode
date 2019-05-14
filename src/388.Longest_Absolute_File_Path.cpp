class Solution {
public:
    int lengthLongestPath(string input) {
        int res = 0;
        istringstream ss(input);
        unordered_map<int, int> m{{0, 0}};
        string line = "";
        while (getline(ss, line)) {
            int level = line.find_last_of('\t') + 1;
            int len = line.substr(level).size();
            if (line.find('.') != string::npos) 
                res = max(res, m[level] + len);
            else 
                m[level + 1] = m[level] + len + 1; //prepare for next level (as part of it, like base, '/' as + 1
        }
        return res;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////

class Solution {
public:
    int lengthLongestPath(string input) {
        vector<string> tokens = getTokens(input);
        int n = tokens.size(), maxLen = 0;
        vector<int> lens(n + 1, 0); //more than necessary...this is the maxsize of lens depth
        vector<string> strs(n + 1, "");
        string tmp, longest;
        for(auto v : tokens) {
            auto pos = v.find_last_of('\t');
            int level = (pos == string::npos) ? 0 : pos + 1;
            int vsize = v.size();
            if(v.find('.') == string::npos) {
                if(level == 0) {
                    lens[level] = v.size();
                    strs[level] = v;
                }
                else {
                    lens[level] = lens[level - 1] + vsize - level;
                    strs[level] = v.substr(level);
                }
            }   
            else { //end of a file
                if(level == 0) {
                    if(vsize > maxLen) {
                        maxLen = vsize;
                        longest = v;
                    }
                }
                else {
                    if(lens[level - 1] + vsize > maxLen) {
                        maxLen = lens[level - 1] + vsize;
                        for(int i = 0; i <= level - 1; ++i)
                            tmp += strs[i] + '/';
                        tmp += v.substr(level);
                        longest = tmp;
                        tmp = "";
                    }
                }
            }
        }
        return maxLen;
    }
};
