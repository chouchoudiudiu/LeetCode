class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while (m != n) { //otherwise there will always be alternating 0 and 1
            m >>= 1;
            n >>= 1;
            ++i;
        }
        return m << i;
    }
};

//
//12
//13
//
