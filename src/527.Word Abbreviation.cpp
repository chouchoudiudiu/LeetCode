class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        int n = dict.size();
        vector<string> res(n);
        vector<int> pre(n, 1);
        for (int i = 0; i < n; ++i) {
            res[i] = abbreviate(dict[i], pre[i]);
        }
        for (int i = 0; i < n; ++i) {
            while (true) {
                set<int> s;
                for (int j = i + 1; j < n; ++j) {
                    if (res[j] == res[i]) s.insert(j);
                }
                if (s.empty()) break;
                s.insert(i);
                for (auto a : s) {
                    res[a] = abbreviate(dict[a], ++pre[a]);
                }
            }
        }
        return res;
    }
    string abbreviate(string s, int k) {
        return (k >= s.size() - 2) ? s : s.substr(0, k) + to_string(s.size() - k - 1) + s.back();
    }
};

/*
由于每个单词的缩写形式中数字前面的字母个数不一定相同，所以我们用一个pre数组来记录每个单词缩写形式开头字母的长度，
初始化都为1，然后先求出所有单词pre为1的缩写形式，再来进行冲突处理。我们遍历每一个缩写字符串，进行while循环，新建一个集合set，
然后遍历其他所有字符串，所有发现冲突字符串，就把冲突字符串的坐标存入集合中，如果没有冲突，那么集合为空，直接break掉，如果由冲突，
那么还要把当前遍历的位置i加入结合中，然后遍历集合中所有的位置，对其调用缩写函数，此时pre对应的值自增1，直到没有冲突存在为止
*/
