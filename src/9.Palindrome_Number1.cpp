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
