class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> m; //cumsum, cnt
        int maxCnt = 0, n = wall.size();;
        for(int i = 0; i < n; ++i) {
            int sum = 0;
            for(int j = 0; j < wall[i].size() - 1; ++j) {
                sum += wall[i][j];
                ++m[sum];
            }
        }
        for(auto v : m) {
            maxCnt = max(maxCnt, v.second);
        }
        
        return n - maxCnt;
    }
};
//find accumulated sum values that get most intersection, actually find 2nd max ...excluding the last (otherwise same!)
//note there is no zero size brick
//wallsize - number of max number in cummulated sums table
