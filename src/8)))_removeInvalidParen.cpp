//this solution is actually incorrect...........
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int maxLen = 0, start = -1, end = -1;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                stk.push(i);
            else {
                if(!stk.empty() && s[stk.top()] == '(') {
                    stk.pop();
                    //maxLen = stk.empty() ? i + 1 : max(maxLen, i - stk.top());
                    //maxLen = max(maxLen, stk.empty() ? i + 1 : i - stk.top());
                    if(stk.empty()) {
                        start = 0;
                        end = i;
                        maxLen = i + 1;
                    }
                    else {
                        if(maxLen < i - (int)stk.top()) {
                            start = (int)stk.top() + 1;
                            end = i;
                            maxLen = i - stk.top();
                        }
                    }
                }
                else
                    stk.push(i);
            }
        }
        if(maxLen != 0)
            cout<<s.substr(start, maxLen)<<endl;
        return maxLen;
    }
};

//just need to return 1 solution
