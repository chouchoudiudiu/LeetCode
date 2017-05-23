class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size(), total = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            if (sentence[i].size() > cols)
                return 0;
            int cnt = 0, len = 0, j = i;
            while (j < n && len + sentence[j].size() <= cols) {
                len += sentence[j].size() + 1; //space
                j = (j + 1) % n;// + 1
                ++cnt;
            }
            m.insert({ i, cnt });
        }
        
        for (int i = 0, j = 0; i < rows; ++i) {
            total += m[j];
            j = (j + m[j]) % n;
        }

        return total / n;
    }
};
