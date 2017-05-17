class Solution {
public:
    int calculate(string s) {
        stack<int> nums, ops; //ops has only +- inside ()
        int sum = 0, temp = 0, sign = 1;//起点处没有符号，默认为加号
        for (auto c : s) {
            if (isdigit(c)) {
                temp = temp*10 + c - '0';
            }   
            else {
                sum += sign * temp;
                temp = 0;
                if (c == '+') sign = 1;
                if (c == '-') sign = -1;
                if (c == '(') {
                    nums.push(sum);
                    ops.push(sign); //进入括号之前的符号
                    sum = 0;//括号里面，一个新的开始，与外面的世界无关,之前的结果被存到了nums里面，每遇到一个(就push一次到nums
                    sign = 1;//和a处一样，相当于起点，默认为+，因为如果下一个数字为负数，会被c == '-'检测出来，'+' is hidden第一个数字
                }
                if (c == ')' && !ops.empty()) {
                    sum = ops.top()*sum + nums.top(); //刚结算完的括号（可能有好多个括号对）里面的值加上之前的sum *，及其符号
                    ops.pop();
                    nums.pop();
                }
            }
        }
        sum += sign * temp;//最后一个字符是数字，不会进入else; 否则进入也没关系，temp = 0
        return sum;
    }
};
