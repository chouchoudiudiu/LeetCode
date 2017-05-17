class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        string half = "", mid = "";
        unordered_map<char, int> m;
        for (auto c : s) ++m[c];
        for (auto v : m) {
            if (v.second % 2 == 1)
                mid += v.first;
            half += string(v.second/2, v.first);
            if (mid.length() > 1)
                return {};//not able to generate palindromes
        }
        permute(half, mid, 0, res); //no need to sort like permutation2 since it is like sorted/grouped
        return res;
    }
    void permute(string& half, string mid, int start, vector<string> &res) {
        if (start >= half.length()) {
            res.push_back(half + mid + string(half.rbegin(), half.rend()));
        }
        unordered_set<char> used;
        for (int i = start; i < half.length(); ++i) {
            if (used.find(half[i]) == used.end()) {
                swap(half[i], half[start]);
                permute(half, mid, start + 1, res);
                swap(half[i], half[start]);
                used.insert(half[i]);
            }
        }
    }
};
