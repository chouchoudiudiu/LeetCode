class Solution {
public:
    int factorial(int n) {
        if (n == 0) return 1;
        int fact = n;
        while (--n > 0) 
            fact *= n;
        return fact;
    }
    
    string helper(string s, int k) {
        if (s.length() == 1 || k == 0)
            return s;
        int N = s.length();
        int i = k/factorial(N - 1);
        int j = k%factorial(N - 1);
        return s[i] + helper(s.substr(0, i) + s.substr(i + 1), j);
    }
    string getPermutation(int n, int k) {
        if (k > factorial(n))
            return "";
        string res = "", s = "";
        for (int i = 0; i < n; ++i) //the first string (k = 1)
            s += i + '1';
        return helper(s, k - 1); //left
    }
};
