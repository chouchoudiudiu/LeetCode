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
    int strobogrammaticInRange(string low, string high) {
        int count = 0;
        for(int i = low.length(); i <= high.length(); i++){
             vector<string> res = helper(i, i);
             for (string num : res) {
                if((num.length() == low.length() && num < low ) ||(num.length() == high.length() && num > high))
                    continue;
				count++;
             }
        }

        return count;
    }
};
//can get count without calculating all the solutions
//MLE
//"0"
//"100000000000000"
