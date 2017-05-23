class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> rows1{'q', 'w','e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        unordered_set<char> rows2{'a', 's', 'd','f', 'g', 'h', 'j', 'k', 'l'};
        unordered_set<char> rows3{'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        vector<string> res;
        for (auto word : words) {
            int one = 0, two = 0, three = 0;
            for (auto c : word) {
                c = tolower(c);
                if (rows1.count(c)) one = 1;
                if (rows2.count(c)) two = 1;
                if (rows3.count(c)) three = 1;
                if (one + two + three > 1)
                    break;
            }
            if (one + two + three == 1)
                res.push_back(word);
        }
        return res;
    }
};
