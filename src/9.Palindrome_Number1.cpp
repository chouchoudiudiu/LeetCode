class Solution {
public:
    bool isPalindrome(int n) {
	if (n < 0 || (n != 0 && n%10 == 0)) //no leading zeros
	    return false;
	int sum = 0;
        while (n > sum) {
            sum = sum*10 + n%10;
            n /= 10;
        }
    
        return sum == n || sum/10 == n; //even, odd; 坏处是 要比完所有？
    }
};
