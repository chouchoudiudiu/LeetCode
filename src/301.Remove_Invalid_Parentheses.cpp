class Solution {
public:
//BFS
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        queue<string> q;
        unordered_set<string> visited;
        q.push(s);
        bool found = false;
        while (!q.empty()) {
            string str = q.front();
            q.pop();
            visited.insert(str);
            if (isValid(str)) { 
                res.push_back(str);
                found = true; //will quit in this level of queue, not going further in delete, minimum
            }
            if (found)
                continue; //not break; continue until q is empty
            for (int i = 0; i < str.length(); ++i) {
                if (str[i] != '(' && str[i] != ')')
                    continue;
                string tmp = str.substr(0, i) + str.substr(i + 1);
                if (visited.find(tmp) == visited.end()) {
                    q.push(tmp);
                    visited.insert(tmp);
                }
            }
        }
        return res;
    }
    
    bool isValid(string s) {
        int cnt = 0;
        for (auto c : s) {
            if (c == '(') ++cnt;
            if (c == ')') --cnt;
            if (cnt < 0) return false;
        }
        return cnt == 0;
    }
};
//["(())()","()()()","()()","(())","()",""] 如果不用found控制，会一直删下去
//"()(())())())"
