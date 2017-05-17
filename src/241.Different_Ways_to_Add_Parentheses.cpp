class Solution {
public:
//number of parenthesis pairs is the same as operator numbers
//similar to Unique Binary Search Trees II 独一无二的二叉搜索树之二
    vector<int> diffWaysToCompute(string input) {
        if (input.empty())
            return {};
        vector<int> res;
        for (int i = 0; i < input.length(); ++i) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (auto l : left)
                    for (auto r : right) {
                        if (input[i] == '+')
                            res.push_back(l + r);
                        if (input[i] == '-')
                            res.push_back(l - r);
                        if (input[i] == '*')
                            res.push_back(l*r);
                    }
            }
        }
        if (res.empty()) //no +-* single number
            res.push_back(stoi(input));
        return res;
    }
};
