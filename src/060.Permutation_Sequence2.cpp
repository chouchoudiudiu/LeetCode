class Solution {
public:
    int factorial(int n) {
        if (n == 0) return 1;
        int fact = n;
        while (--n > 0) 
            fact *= n;
        return fact;
    }
    
    string getPermutation(int n, int k) {
        if (k > factorial(n))
            return "";
        string res = "", s = "";
        for (int i = 0; i < n; ++i) //the first string (k = 1)
            s += i + '1';
        k = k - 1; //k = k - 1
        while (k >= 0 && s.length() > 0) {
            int N = s.length();
            int i = k/factorial(N - 1);
            int j = k%factorial(N - 1);
            res += s[i];
            s.erase(s.begin() + i);
            k = j;
        }
        return res;
    }
};
