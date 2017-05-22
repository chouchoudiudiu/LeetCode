class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while (i < word.size() && j < abbr.size()) {
            if (isdigit(abbr[j])) {
                if (abbr[j] == '0')
                    return false; //no zero or leading zero, 10 is okay inside while
                int val = 0;
                while (isdigit(abbr[j]))
                    val = val * 10 + abbr[j++] - '0';
                i += val;
            }
            else if (word[i++] != abbr[j++])
                return false;
        }
        return i == word.size() && j == abbr.size();
    }
    
    void helper(vector<pair<int, string>>& res, string out, string word, int curIdx, int cnt, int reduced) {
        if (curIdx == word.size()) {
            if (cnt > 0)
                out += to_string(cnt);
            res.push_back({max(cnt - 1, 0) + reduced, out });//note len, not len + 1
            return;
        }
        helper(res, out, word, curIdx + 1, cnt + 1, reduced); //not using word[curIdx]
        helper(res, out + (cnt > 0 ? to_string(cnt) : "") + word[curIdx], word, curIdx + 1, 0, max(cnt - 1, 0) 
        + reduced);//use, reset cnt; the more you call this, the more shorten you get, cnt表示省略了多少
    }
    
    string minAbbreviation(string target, vector<string>& dictionary) {
        if (dictionary.empty()) 
            return to_string((int)target.size());
        vector<pair<int, string>> abbrs;
        helper(abbrs, "", target, 0, 0, 0);
        sort(abbrs.begin(), abbrs.end(), greater<pair<int, string>>());//shorter comes first, greater, reduced
        for (auto& abbr : abbrs) {
            int i = 0;
            for(; i < dictionary.size(); ++i)
            {
                if(validWordAbbreviation(dictionary[i], abbr.second)) //valid -> break! means a conflict is found
                    break;
            }
            if(i == dictionary.size())//pass all words in dict and didn't find a conflict
                return abbr.second;
        }
        return ""; //no ans found
    }
};
