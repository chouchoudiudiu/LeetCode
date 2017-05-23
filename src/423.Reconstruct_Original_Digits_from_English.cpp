class Solution {
public:
    string originalDigits(string s) {
        string res;
        vector<string> words = { "zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine" };
        vector<char> nums = { '0', '2', '4', '6', '8', '1', '3', '5', '7', '9' };
        vector<char> uniques = { 'z', 'w', 'u', 'x', 'g', 'o', 'r', 'f', 'v', 'i' };
        int counter[26] = { 0 };
        for (auto c : s)
            ++counter[c - 'a'];
        for (int i = 0; i < uniques.size(); ++i) {// one by one
            int cnt = counter[uniques[i] - 'a'];
            for (int j = 0; j < words[i].size(); ++j)
                counter[words[i][j] - 'a'] -= cnt; //一次减完
            while (cnt--) {
                res.push_back(nums[i]);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

//"ereht" MLE
