class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        int sum = 0, tmp = 0;
        char sign = '+';//remeber the last sign
        for (int i = 0; i < s.length();) {
            while (isdigit(s[i])) //second number saved in tmp now, waiting for the next ops 
                tmp = tmp*10 + s[i++] - '0';
            if (!isspace(s[i]) || i == s.length() - 1) {//an end  the 2nd check is needed, " 5 +3/2 "
                if (sign == '+') nums.push(tmp);
                if (sign == '-') nums.push(-tmp);
                if (sign == '*' || sign == '/') {
                    int val = (sign == '*') ? nums.top() * tmp : nums.top()/tmp;
                    nums.pop();
                    nums.push(val);
                }
                sign = s[i];//even last char is okay
                tmp = 0;
            }
            ++i;
        }
        while (!nums.empty()) {
            sum += nums.top();
            nums.pop();
        }
        return sum;
    }
};
//" 5 +133/22 " 等计算完一个新的数字时候判定是否已到结尾，记录的是前一个符号，22while结束后提取它之前读入的符号
