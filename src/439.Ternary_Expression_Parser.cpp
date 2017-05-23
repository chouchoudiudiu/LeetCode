class Solution {
public:
    string parseTernary(string expression) {
        stack<char> stk;
        bool evaluate = false;
        for (int i = expression.size() - 1; i >= 0; --i) {
            char c = expression[i];
            if (!evaluate && c != ':' && c != '?') //not adding the T or F before the ?
                stk.push(c);
            if (evaluate) {
                char T = stk.top();
                stk.pop();
                char F = stk.top();
                stk.pop();
                stk.push(c == 'T' ? T:F);
                evaluate = false;
            }
            if (c == '?') 
                evaluate = true;
        }
        string s = "";
        return expression.empty() ? s : s + stk.top();
    }
};
