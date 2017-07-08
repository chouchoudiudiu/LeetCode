class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        if(picture.empty())
            return 0;
        int m = picture.size(), n = picture[0].size();
        int cnt = 0;
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        for(int i = 0; i < m; ++i) 
            for(int j = 0; j < n; ++j) {
                if(picture[i][j] == 'B') {
                    ++rows[i];
                    ++cols[j];
                }
            }
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if(picture[i][j] == 'B') {
                    if(rows[i] == 1 && cols[j] == 1)
                        ++cnt;
                }
            }
        return cnt;
    }
};
