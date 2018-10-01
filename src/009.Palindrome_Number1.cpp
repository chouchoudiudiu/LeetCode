class Solution {
public:
    bool isPalindrome(int x) {
	if (x < 0 || (x != 0 && x%10 == 0)) //no leading zeros
	    return false;
	int sum = 0;
        while (x > sum) {
            sum = sum*10 + x%10;
            x /= 10;
        }
    
        return sum == x || sum/10 == x; //even, odd; 坏处是 要比完所有？
    }
};


=============
	class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        long long rev = 0; //其实int, long 也可
        int x_p = x; //x will change in the end
        while(x) {
            rev = rev*10 + x%10;
            x /= 10;
        }
        return rev == x_p;
    }
};
