class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> code;
        for (int i = 0; i < (1<<n); ++i) { //3->8
            code.push_back(i ^ (i>>1));
        }
        return code;
    }
};

///////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> codes;
        codes.push_back(0);
        for (int i = 0; i < n; ++i) { //3->8
            for (int j = codes.size() - 1; j >= 0; --j) {
                codes.push_back(codes[j] ^ (1<<i));
            }
        }
        return codes;
    }
};
