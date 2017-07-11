class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if(picture.empty())
            return 0;
        int m = picture.size(), n = picture[0].size();
        vector<string> strRows;
        unordered_map<string, int> map; //strrow, freq
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        for(int i = 0; i < m; ++i) {
            string s = "";
            for(int j = 0; j < n; ++j) {
                if(picture[i][j] == 'B') {
                    ++rows[i];
                    ++cols[j];
                }
                s += picture[i][j];
            }
            ++map[s];
            strRows.push_back(s);
        }
        int cnt = 0;
        for(int i = 0; i < m; ++i) {
            if(rows[i] == N && map[strRows[i]] == N) {//该row有N个B,说明该col也有N个B，也就是要有N个和它相同的row
                for(int j = 0; j < n; ++j) {
                    if(picture[i][j] == 'B' && cols[j] == N)//exactly same place
                        ++cnt;
                }
            }
        }
        
        return cnt;
    }
};
