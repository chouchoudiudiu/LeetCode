class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n%10)*(n%10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int num = n;
        unordered_set<int> set;
        while (true) {
            n = getSum(n);
            if (n == 1)
                return true;
            if (set.count(n))
                return false;
            set.insert(n);
        }
        return false;
    }
};
