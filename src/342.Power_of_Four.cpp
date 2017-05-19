class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0)
            return false;
        int n = (int)sqrt(num);
        if (n * n != num)
            return false;
        return !(n & (n - 1));
    }
};


///////////////////////////////
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0)
            return false;
        if(num == 1)
            return true;
        while(num > 4)
        {
            if(num %4 != 0)
                return false;
            num /= 4;
        }
        return num%4 == 0;
    }
};
