class Solution {
public:
    void dfs(vector<string>& res, string s, string leftNum, long long last, long long curVal, int target) {
        if (leftNum.length() == 0 && curVal == target) {
            res.push_back(s);
            return;
        }
        for (int i = 1; i <= leftNum.length(); ++i) {
            string currNum = leftNum.substr(0, i);
            string nextNum = leftNum.substr(i);
            if (currNum.length() > 1 && currNum[0] == '0') //"00 + 0", "00 - 0"
                return;
            if (s.length() > 0) {//not the first letter
                dfs(res, s + '+' + currNum, nextNum, stoll(currNum), curVal + stoll(currNum), target);
                dfs(res, s + '-' + currNum, nextNum, -stoll(currNum), curVal - stoll(currNum), target);//last is - here
                dfs(res, s + '*' + currNum, nextNum, last*stoll(currNum), (curVal - last) + last*stoll(currNum), target);//roll back
            }
            else
                dfs(res, currNum, nextNum, stoll(currNum), stoll(currNum), target);
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(res, "", num, 0, 0, target); //s:output
        return res;
    }
};
