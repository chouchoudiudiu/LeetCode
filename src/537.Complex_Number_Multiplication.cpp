class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ra = parse(a).first;
        int rb = parse(b).first;
        int ia = parse(a).second;
        int ib = parse(b).second;
        return to_string(ra*rb - ia*ib) + "+" + to_string(ra*ib + rb*ia) + "i"; 
    }
    pair<int, int> parse(string s) {
        int plus = find(s.begin(), s.end(), '+') - s.begin();
        int rpart = stoi(s.substr(0, plus));
        int ipart = stoi(s.substr(plus + 1, s.size() - plus - 1)); //removing i
        return {rpart, ipart};
    }
};
