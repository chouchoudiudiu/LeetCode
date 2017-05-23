class Solution {
public:
    void helper(vector<vector<string>>& res, vector<string>& square, vector<string>& words, unordered_map<string, vector<string>>& m, 
        int i) {
        if (i == words[0].length()) { //words[0].length()
            res.push_back(square);
            return;
        }
        string prefix;
        for (int k = 0; k < i; ++k) //对当前确定的0-i - 1行，取第i个字母，如l(wall的第三个字母); e(area的第三个字母)
            prefix += square[k][i]; //到wall做第一行时候，接着确定了第二行为area，也就是prefix为a,到第三行，找prefix为le
        for (auto v : m[prefix]) { //i = 0, 因为""也是一个prefix, 所以这就等于遍历所有word作为第一个单词
            square[i] = v;
            helper(res, square, words, m, i + 1);
        }
    }
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        if (words.empty())
            return {};
        vector<vector<string>> res;
        vector<string> square(words[0].length()); //words[0].length()
        unordered_map<string, vector<string>> m;
        for (auto word : words) {
            for (int i = 0; i < word.size(); ++i) {
                string s = word.substr(0, i);//prefix, including ""
                m[s].push_back(word);
            }
        }
        
        helper(res, square, words, m, 0);
        return res;
    }
};
/*
try every word for the first row. For each of them, try every fitting word for the second row. And so on. The first few rows determine the first few columns and thus determine how the next row's word must start. For example:
*/
