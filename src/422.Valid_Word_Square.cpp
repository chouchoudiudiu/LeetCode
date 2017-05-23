class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < words[i].size(); ++j) {
                if (i >= words[j].size() || j >= n) //words[j], not i; >= 
                    return false;
                if (words[i][j] != words[j][i])//i合理范是0-n j合理范围0-words[j].size();保证words['j']['i']
                    return false;
            }
        return true;
    }
};
