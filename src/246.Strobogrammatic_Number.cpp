class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = num.length();
        unordered_map<char, char> m = {{'1', '1'}, {'6','9'}, {'8', '8'}, {'9', '6'}, {'0', '0'}};
        for (int l = 0, r = n - 1; l <= r; ++l, --r) {
            if (m.find(num[l]) == m.end() || m[num[l]] != num[r])
                return false;
        }
        return true;
    }
};
/*
class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = num.length();
        for (int i = 0; i <= n/2; ++i) {
            if (num[i] != '0' && num[i] != '1' && num[i] != '8' && num[i] != '6' && num[i] != '9')
                return false;
            if (num[i] != num[n - 1 - i] && num[i] != '6' && num[i] != '9')
                return false;
            if ((num[i] == '6' && num[n - 1 - i] != '9') || (num[i] == '9' && num[n - 1 - i] != '6') )
                return false;
        }
        return true;
    }
};*/
