class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int multi = 1; //long to avoid overflow if use multi*10 < x
        while (x/multi >= 10)
            multi *= 10; //if 12321, multi = 10000
        while (x) {
            int left = x/multi;
            int right = x%10;
            if(left != right)
                return false;
            x = (x%multi)/10; //12321 now becomes 232
            multi /= 100;
        }
        
        return true;
    }
};

/*
        long multi = 1; //long to avoid overflow if use multi*10 < x
        while (multi*10 < x)
            multi *= 10; //if 12321, multi = 10000
*/
