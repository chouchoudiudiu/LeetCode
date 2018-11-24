class Solution {
public:
    string findorigin(string s) {
        if (s.empty()) return s;
        string origin = s;
        origin[0] = 'a';
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] - s[0] < 0)
                origin[i] = s[i] - s[0] + 'a' + 26; //loop
            else
                origin[i] = s[i] - s[0] + 'a';
        }
        return origin;
    }

    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, vector<int>> m;
        for (int i = 0; i < strings.size(); ++i) {
            string origin = findorigin(strings[i]);
            m[origin].push_back(i);
        }
        for (auto v : m) {
            vector<string> onegroup;
            for (auto id : v.second) 
                onegroup.push_back(strings[id]);
            res.push_back(onegroup);
        }
        return res;
    }
};


////////
 vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> u_map;
        for(auto s : strings) {
            string origin = findOrigin(s);
            u_map[origin].push_back(s);
        }
        for(auto m : u_map) 
            res.push_back(m.second);
        return res;
    }
