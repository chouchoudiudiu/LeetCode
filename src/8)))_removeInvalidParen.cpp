https://instant.1point3acres.com/thread/180240
https://instant.1point3acres.com/thread/161681
用一个counter，每次遇到左括号加一；每次遇到右括号先判断counter是否为零：
为零说明右括号多了，删除当前右括号，不为零说明合法，counter减一。
遍历一遍以后可以看看counter是否大于零，如果是则从右数起删除多余的左括号。

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> strs;
        int cnt = 0;
        string output, res;
        for(auto c : s) {
            if(c == '(') {
                ++cnt;
                output += c;
            }
            else if(c == ')'){
                if(cnt == 0)
                    continue; //not adding
                else {
                    output += c;
                    --cnt;
                }
            }
        }
        for(int i = output.size() - 1; i >= 0; --i) {
            if(cnt > 0 && output[i] == '(')
                --cnt;
            else
                res += output[i];
        }
        reverse(res.begin(), res.end());
        strs.push_back(res);
        return strs;
    }
};


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
