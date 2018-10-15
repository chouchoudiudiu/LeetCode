class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        for (auto v : nums) {
            if(v == first || v == second || v == third)
                continue;
            if (v > first) {
                third = second;
                second = first;
                first = v;
            }
            else if (v > second) {
                third = second;
                second = v;
            }
            else if (v > third) 
                third = v;
        }
        return third != LONG_MIN  ? third : first;
    }
};

//[1,2,2,5,3,5]
//[1,2,-2147483648]

//return (third != LONG_MIN  && third != second) ? third : first;
