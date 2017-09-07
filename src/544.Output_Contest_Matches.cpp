class Solution {
public:
    string findContestMatch(int n) {
        vector<string> m(n);
        for(int i = 0; i < n; ++i)
            m[i] = to_string(i + 1);
        while(n > 1) { //until n == 2 so n/2 = 1, last m[0]
            for(int i = 0; i < n/2; ++i)
                m[i] = '(' + m[i] + ',' + m[n - 1 - i] + ')';
            n /= 2;    
        }
        return m[0];
    }
};

// 1 2 3 4 5 6 7 8
//两两合并
