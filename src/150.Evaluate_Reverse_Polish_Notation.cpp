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

=========
    class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(auto s : tokens) {
            if(s != "*" && s != "+" && s != "-" && s != "/") 
                stk.push(stoi(s));
            else {
                int val1 = stk.top();
                stk.pop();
                int val2 = stk.top();
                stk.pop();
                if(s == "+")
                    stk.push(val1 + val2);
                if(s == "-")
                    stk.push(val2 - val1);
                if(s == "*")
                    stk.push(val1*val2);
                if(s == "/")
                    stk.push(val2/val1);
            }
        }
        return stk.top();
    }
};
