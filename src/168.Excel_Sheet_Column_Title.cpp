class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while (n) {
            s += char((--n)%26 + 'A'); //char
            n /= 26;
        }
        return string(s.rbegin(), s.rend());
    }
};



class Solution {
public:
    string convertToTitle(int n) {
        return n == 0 ? "" : convertToTitle(n / 26) + (char)(--n % 26 + 'A');
    }
};

class Solution {
public:
    string convertToTitle(int n) {
        string s(1, (n - 1)%26 + 'A'); //'A' -> 1
        n = (n - 1)/26;
        while (n) {
            s = char((n - 1)%26 + 'A') + s; //char
            n = (n - 1)/26;
        }
        return s;
    }
};
