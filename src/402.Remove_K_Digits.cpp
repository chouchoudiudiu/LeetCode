class Solution {
public:
    string removeKdigits(string num, int k) {
        //becomes finding maximum num, but should consider leading zero problem
        int n = num.size(), len = n - k;
        string res(len, '9');//in finding max, 0, 也许也没关系是几？
        for (int i = 0, j = 0; i < n; ++i) {
            while (j + n - i > len && num[i] < res[j - 1]) 
                j--;
            if (j < len)
                res[j++] = num[i];
        }
        //delete leading zeros
        int zeros = 0;
        while (res[zeros] == '0')
            ++zeros;
        res.erase(0, zeros); //string& erase (size_t pos = 0, size_t len = npos);*/
        return res == "" ? "0" : res;
    }
};
//"10"
//2
//"22222222222222222222222222222222222222"
//20  free(): invalid next size (fast): 0x000000000115df70 ***
