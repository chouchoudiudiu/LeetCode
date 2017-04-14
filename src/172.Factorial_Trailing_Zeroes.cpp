class Solution {
public:
    int trailingZeroes(int n) {
        //count number of 5s, will always match with 2s; 5*5s will match 4s; plenty of multiples of 2s...
        int count = 0;
        while (n > 0) {
            count += n/5;
            n /= 5; // 80 -> 16 (5*5*1, 5*5*2, 5*5*3)
        }
        return count;
    }
};
