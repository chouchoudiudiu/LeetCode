class Solution {
public:
    void helper(vector<string>& res, string out, string word, int curIdx, int cnt) {
        if (curIdx == word.size()) {
            if (cnt > 0)
                out += to_string(cnt);
            res.push_back(out);
            return;
        }
        helper(res, out, word, curIdx + 1, cnt + 1); //not using word[curIdx]
        helper(res, out + (cnt > 0 ? to_string(cnt) : "") + word[curIdx], word, curIdx + 1, 0);//use, reset cnt
    }
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        helper(res, "", word, 0, 0);
        return res;
    }
};

//count记录当前选用Letter的index与下一个选用的letter的index的距离。dfs1表示跳过（未选用）当前letter，继续check下一个，所以count + 1;
    //若选用了当前letter，count清零，因为需要重新开始当前字符雨下一个字符之间间隔的字符数目
