class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> res(n + 1, 0);
        int carry = 1;
        for (int i = n - 1; i >= 0; --i) {
            int sum = digits[i] + carry;
            res[i + 1] = sum%10;
            carry = sum/10;
            if (i == n - 1 && carry == 0) {
                digits[i] += 1;
                return digits; //no more calculation needed
            }
        }
        if (carry > 0)
            res[0] = carry;
        else
            res.erase(res.begin());
        return res;
    }
};
