class Solution {
public:
    vector<string> helper(int n, int N){ //N is original n
        if (n == 0)
            return {""}; //will add chars on left/right in next layer
        if (n == 1)
            return {"0", "1", "8"};
        vector<string> tmp = helper (n - 2, N);
        vector<string> res; 
        for (auto v : tmp) {
            if (n != N) //when equal, can't add
                res.push_back('0' + v + '0');
            res.push_back('1' + v + '1');
            res.push_back('6' + v + '9');
            res.push_back('9' + v + '6');
            res.push_back('8' + v + '8');
        }
        return res;
    }
    vector<string> findStrobogrammatic(int n) {
        vector<string> res = helper(n, n);
        return res;
    }
};

/*
加到了n层的时候，左右两边不能加[0 0]，因为0不能出现在两位数及多位数的开头，在中间递归的过程中，需要有在数字左右两边各加上0的那种情况
*/
