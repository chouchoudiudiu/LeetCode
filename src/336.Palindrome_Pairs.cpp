class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> m; //where its match should be
        for (int i = 0; i < words.size(); ++i) {
            string s = words[i];
            reverse(s.begin(), s.end());
            m[s] = i;
        }
        for (int i = 0; i < words.size(); ++i) {
            string s = words[i];
            for (int j = 0; j < s.size(); ++j) {
                string left = s.substr(0, j);
                string right = s.substr(j);
                if (isPalindrome(left) && m.find(right) != m.end() && m[right] != i) //not self!
                    res.push_back({m[right], i});
                if (isPalindrome(right) && m.find(left) != m.end() && m[left] != i)
                    res.push_back({i, m[left]}); //i instead of j
            }
        }
        //corner case for ""
        if (m.find("") != m.end()) {
            for (int i = 0; i < words.size(); ++i) {
                string s = words[i];
                if (s != "" && isPalindrome(s))
                    res.push_back({m[""], i});
            }
        }
        return res;
    }
    
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
};
//["a",""]
//["a","",""] unique! so no more than 1 ""
