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
    bool helper(char c1, char c2) {
        return (c1 == '0' && c2 == '0') || (c1 == '1' && c2 == '1') || (c1 == '8' && c2 == '8') || (c1 == '6' && c2 == '9') || (c1 == '9' &&                c2 == '6');
    }
    bool isStrobogrammatic(string num) {
        int l = 0, r = num.length() - 1;
        while(l <= r) {
            if(!helper(num[l++], num[r--]))
                return false;
        }
        return true;
    }
};*/
