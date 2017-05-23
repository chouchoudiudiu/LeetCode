class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> letters(26, 0); //记录以该字母结尾的最长连续串的长度，则为以该字母结尾所有贡献出的合理子串，往左看，zabc(c,bc,abc,zabc)
        int len = 0;
        for (int i = 0; i < p.size(); ++i) {
            if (i >= 1 && (p[i] == p[i - 1] + 1) || (p[i] == 'a' && p[i - 1] == 'z' )) //valid
                ++len; //新读入一个字母，只要关心它是否增加了以它结尾的解，前面的解都已固定，与之无关
            else
                len = 1; //reset
            letters[p[i] - 'a'] = max(letters[p[i] - 'a'], len); //有可能重复出现同样的子串，有长有短，比如前面zabc后面zab
        }
        return accumulate(letters.begin(), letters.end(), 0);
    }
};
//"zabtabc"
//a ab abc abcd abcde abcdef abcdefg
//1  1+2=3   1+2+3=6   10    15     21      28
//abc到c时候增加的解为c, bc, abc
