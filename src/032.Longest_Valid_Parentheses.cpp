class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int maxLen = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                stk.push(i);
            else {
                if (!stk.empty() && s[stk.top()] == '(') {
                    stk.pop();
                    maxLen = max(maxLen, stk.empty() ? i + 1 : i - stk.top());
                    //maxLen = stk.empty() ? i + 1 : max(maxLen, i - stk.top()); //both okay
                }
                else
                    stk.push(i);//last occurrence of not matched ')'
            }
        }
        return maxLen;
    }
};
