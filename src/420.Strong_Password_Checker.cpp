class Solution {
public: //copied...
    int strongPasswordChecker(string s) {
        int res = 0, n = s.length(), lower = 1, upper = 1, digit = 1;
        vector<int> v(n, 0); //count repeating charcters
        for(int i = 0; i < n;)
        {
            if(s[i] >= 'a' && s[i] <= 'z')  lower = 0; //no more requirement
            if(s[i] >= 'A' && s[i] <= 'Z')  upper = 0;
            if(s[i] >= '0' && s[i] <= '9')  digit = 0;
            int j = i;
            while(i < n && s[j] == s[i])   ++i; 
            v[j] = i - j; //starting with original i, repeating
        }
        int missing = (lower + upper + digit);
        if(n < 6)
        {
            int diff = 6 - n;
            res = diff + max(0, missing - diff);
        }
        else
        {
            int over = max(0, n - 20), replace = 0;//解决重复字符最少需要替换的个数
            res = over;
            for(int k = 1; k <= 2; ++k)
                for(int i = 0; i < n && over >= k; ++i)//over > 0 -> over >= k
                {
                    if(v[i] < 3 || v[i]%3 != (k - 1))
                        continue;
                    v[i] -= k;
                    over -= k;
                }

            for(int i = 0; i < n; ++i)
            {
                if(v[i] >= 3 && over > 0)
                {
                    int need = v[i] - 2;
                    v[i] -= over;
                    over -= need; //delete 3m directly
                }
                if(v[i] >= 3)   
                    replace += v[i]/3;
            }

            res += max(missing, replace);
        }
        return res;
    }
}; //"1234567890123456Baaaa"
