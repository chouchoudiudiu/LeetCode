class Solution {
public:
    int maxProduct(vector<string>& words) {
        //convert each word to a number
        vector<int> wordBits;
        for (string w : words) {
            int num = 0;
            for (char c : w) {
                num |= (1 << (c - 'a')); //lowcase 26 is enough
            }
            wordBits.push_back(num);
        }
        int maxProd = 0;
        for (int i = 0; i < words.size(); ++i)
            for (int j = 0; j < words.size(); ++j) {
                if ((wordBits[i] & wordBits[j]) == 0) {//totally different, add ()
                    int product = words[i].length() * words[j].length();
                    maxProd = max(maxProd, product);
                }
            }
        return maxProd;
    }
};

================
    class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> wordBits;
        for(auto w : words) {
            int val = 0;
            for(auto c : w) {
                val |= 1<<(c - 'a');
            }
            wordBits.push_back(val);
        }
        int maxLen = 0;
        for(int i = 0; i < words.size(); ++i)
            for(int j = 0; j < words.size(); ++j) {
                if((wordBits[i] & wordBits[j]) == 0) {
                    maxLen = max(maxLen, (int)words[i].length()*(int)words[j].length());
                }
            }
        return maxLen;
        
    }
};

//两数字xor只要有一位不同则结果不为0，要所有位都相同才为0；无法找出所有位都不同的情况，可以找出所有位都相同的情况（为0）
//两数字and只要有一位相同则结果不为0，所有位都不相同则为0；可以找出所有位都不同的情况（为0），无法找出所有位都相同的情况
