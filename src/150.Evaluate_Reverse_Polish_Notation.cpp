class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto v : tokens) {
            if (v != "+" && v != "-" && v != "*" && v != "/")
                stk.push(stoi(v));
            else {
                int tmp = 0;
                int op1 = stk.top();
                stk.pop();
                int op2 = stk.top();
                stk.pop();
                switch(v[0]) { //v[0] as char
                    case '+' : tmp = op1 + op2;
                               break;
                    case '-' : tmp = op2 - op1;
                               break;
                    case '*' : tmp = op1 * op2;
                               break;
                    case '/' : tmp = op2 / op1;
                               break;
                }
                stk.push(tmp);
            }
        }
        return stk.top();
    }
};
