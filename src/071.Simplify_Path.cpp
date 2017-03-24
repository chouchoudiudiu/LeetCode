class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk;
        string res, token;
        stringstream ss(path);
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".")
                continue;
            if (token == ".." && !stk.empty())
                stk.pop_back();
            else if (token != "..") //for below case
                stk.push_back(token);
        }
        for (auto s:stk)
            res += "/" + s;
        
        return res.empty() ? "/": res;
    }
};

//  "/.."
