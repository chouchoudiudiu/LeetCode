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