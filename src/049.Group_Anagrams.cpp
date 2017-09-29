class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for(auto v : strs) {
            string s = v; //dont modify the value of strs
            sort(s.begin(), s.end()); 
            m[s].push_back(v);
        }
        for(auto v : m) 
            res.push_back(v.second);
        return res;
    }
};
