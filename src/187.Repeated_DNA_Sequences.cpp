class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.length() <= 10)
            return res;
        unordered_map<int, int> m; //code, freq
        unordered_map<char, int> dict = {{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
        int i = 0, code = 0;
        while (i < 9) //get first 18 bits
            code = (code<<2) + dict[s[i++]];
        while (i < s.length()) {
            code = ((code & (0x3ffff)) << 2) + dict[s[i++]]; //0x3ffff 1<<18
            m[code]++;
            if(m[code] == 2) {//not >= 2, first show up!
                res.push_back(s.substr(i - 10, 10));
            }
        }
        return res;
    }
};

// The idea is to use rolling hash technique or in case of string search also known as Rabin-Karp algorithm. 
//不需要encode函数，因为10位的ACGT，每一个字符用两位bit表示就是20位，下一次的code值//=取当前code末18位左移两位，然后加上新的char对应的bit
