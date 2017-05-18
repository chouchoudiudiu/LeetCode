class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        for (auto d : dictionary) {
            int n = d.length();
            string s = n <= 2 ? d : (d[0] + to_string(n - 2) + d[n - 1]);
            m[s].insert(d); //字典中缩写形式相同的词放到一个set中
        }
    }
    
    bool isUnique(string word) {//如果要判定的词和字典中的词一样，可以
        int n = word.length();
        string s = n <= 2 ? word : (word[0] + to_string(n - 2) + word[n - 1]);
        return m[s].count(word) == m[s].size(); //is it unique
    }
    
    unordered_map<string, unordered_set<string>> m;
};
/*
["ValidWordAbbr","isUnique","isUnique","isUnique","isUnique"]
[[["door","door","cake","card"]],["door"],["dear"],["cart"],["cake"]]
[null,true,false,true,true]

can further save space by unordered_map<string, string> m;
*/
/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
