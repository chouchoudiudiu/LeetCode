class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int i = 1; i <= n/2; ++i)
            for (int j = 1; j <= (n - i)/2; ++j) {
                if (eval(num.substr(0, i), num.substr(i, j), num.substr(i + j)))
                    return true;
            }
        return false;
    }
    bool eval(string s1, string s2, string s3) {
        if ((s1.size() > 1 && s1[0] == '0') || (s2.size() > 1 && s2[0] == '0') ) //leading 0
            return false;
        string sum = add(s1, s2);
        if (sum == s3) //已经找到
            return true;
        if ((sum.size() >= s3.size()) || (sum != s3.substr(0, sum.size())))
            return false;//长度超过剩余，长度相等值却不等，和与s3前几位不等
        
        return eval(s2, sum, s3.substr(sum.size()));
    }
    //add is faster than stoll + stoll?
    string add(string n1, string n2) {
        string res;
        int i = n1.size() - 1, j = n2.size() - 1, carry  = 0;
        while (i >= 0 || j >= 0) {
            int sum = carry + (i >= 0 ? (n1[i--] - '0') : 0) + (j >= 0 ? (n2[j--] - '0') : 0);
            res.push_back(sum%10 + '0');
            carry = sum/10;
        }
        if (carry) res.push_back(carry + '0');
        reverse(res.begin(), res.end());
        return res;
    }
};
//"199110199" note: very slow! string sum = to_string(stoll(s1) + stoll(s2));
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        for(int i = 1; i <= n/2; ++i) //<=
            for(int j = 1; j <= (n - i)/2; ++j){// (3-1)/2
                if(eval(num.substr(0, i), num.substr(i, j), num.substr(i + j)))
                    return true;
        }
        return false;
    }
    bool eval(string s1, string s2, string s3) {//no leading zeros for each of them
        if ((s1.size() > 1 && s1[0] == '0') || (s2.size() > 1 && s2[0] == '0') ) //leading 0
            return false;
        string sum = add(s1, s2);
        if(sum == s3) //已经找到，就是它了
            return true;
        if(sum.size() >= s3.size() || sum != s3.substr(0, sum.size()))
            return false; //长度超过剩余，长度相等值却不等，和与s3前几位不等
        return eval(s2, sum, s3.substr(sum.size()));//keep trying, not s3
    }
    string add(string s1, string s2) {
        return to_string(stoll(s1) + stoll(s2));
    }
};

//add的写法比自己写一个快似乎？
