class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto c:s) {
            if (c == '(' || c == '[' || c == '{')
                stk.push(c);
            else {
                if (stk.empty())
                    return false;
                if (c == ')' && stk.top() != '(')
                    return false;
                if (c == ']' && stk.top() != '[')
                    return false;
                if (c == '}' && stk.top() != '{')
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};

===================
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto c : s) {
            if(c == '(' || c == '{' || c == '[')
                stk.push(c);
            else {
                if(stk.empty())
                    return false;    
                if(c == ')' && stk.top() == '(')
                    stk.pop();
                else if(c == ']' && stk.top() == '[')
                    stk.pop();
                else if(c == '}' && stk.top() == '{')
                    stk.pop();
                else
                    return false;
            }
        }
        return stk.empty();
    }
};
