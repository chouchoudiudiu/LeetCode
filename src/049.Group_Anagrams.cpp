class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<int>>  m;
        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i]; //dont modify the value of strs
            sort(s.begin(), s.end());
            //if (m.count(s))
                m[s].push_back(i);
            //else
             //   m.insert({s, {i}}); // {i} as a new vector
        }
        for (auto v:m) {
            auto vec = v.second;
            vector<string> temp;
            for (int i = 0; i < vec.size(); ++i) {
                temp.push_back(strs[vec[i]]);
            }
            res.push_back(temp);
        }
        return res;
    }
};
