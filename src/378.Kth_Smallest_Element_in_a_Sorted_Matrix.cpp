class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue< pair<int,pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int,pair<int, int>>>> pq; //min heap
        int res = -1, n = matrix.size();
        for (int i = 0; i < n; ++i) 
            pq.push({matrix[i][0], {i, 0}});
        for (int i = 0; i < k; ++i) {
            res = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if (y < n - 1)
                pq.push({matrix[x][y + 1], {x, y + 1}}); //not ++
        }
        
        return res;
    }
};
//O(klogn)
//priority_queue< pair<int,pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int,pair<int, int> >>> p;
