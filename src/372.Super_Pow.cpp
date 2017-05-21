class Solution {
public:
//Least significant bit -> most significant bit; not modify b
//2^23 = (2^10)^2 * 2^3 ; doesn't modify b
    int superPow(int a, vector<int>& b) {
        int res = 1, mod = 1337;
        a %= mod;
        for (int i = b.size() - 1; i >= 0; --i) { 
            for (int j = 0; j < b[i]; ++j)
                res = (res*a) % mod;
            for (int j = 0, aa = a; j < 9; ++j) //not <=
                a = (a*aa) % mod;
        }
        return res;
    }
};

//////////////////////////
class Solution {
public:
    int mypow (int x, int n, int y) { //x^n mod y, 0 <= n <= 10
        x %= y;
        int i = 0, res = 1;
        while (++i <= n) 
            res = (res * x)%y;
        return res;
    }
    
    int superPow(int a, vector<int>& b) {
        if (b.empty())  
            return 1; //important, for recursion
        int d = b.back();//last digit
        b.pop_back(); //修改了输入
        int y = 1337;
        return (mypow(superPow(a, b), 10, y) * mypow(a, d, y))%y;
    }
};
