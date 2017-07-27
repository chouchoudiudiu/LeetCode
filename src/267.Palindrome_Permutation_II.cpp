class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        unordered_map<char, int> m;
        string half = "", mid = "";
        for(auto c : s)
            ++m[c];
        bool odd = false;
        for(auto v : m) {
            if(v.second%2 == 1)
                mid += v.first; //直接接上单次出现的字符
            half += string(v.second/2, v.first); //相同的字符放在一起，/2
            if(mid.length() > 1)
                return {}; //not able to generate palindromes
        }
        helper(half, mid, res, 0); //通过swap改变half的值，不需要另外写out
        return res;
    }
    void helper(string half, string mid, vector<string>& res, int i) {
        if(i == half.size()) {
            res.push_back(half + mid + string(half.rbegin(), half.rend()));
        }   
        unordered_set<char> used;
        for(int j = i; j < half.size(); ++j) {
            if(used.find(half[j]) == used.end()) { //same as permutation ii, 一样的字母swap没有意义
                swap(half[j], half[i]);
                helper(half, mid, res, i + 1);
                swap(half[j], half[i]);
                used.insert(half[j]);
            }
        }
    }
};
