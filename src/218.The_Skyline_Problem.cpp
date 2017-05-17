class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> results;
        vector<pair<int, int>> boundaries;
        for(auto b:buildings) {
            boundaries.push_back({b[0], -b[2]});
            boundaries.push_back({b[1], b[2]});
        }
        sort(boundaries.begin(), boundaries.end());
        multiset<int> heights;//ordered
        heights.insert(0);
        int prev = 0, curr = 0;
        for(auto b:boundaries) {
            if(b.second < 0)
                heights.insert(-b.second);
            else
                heights.erase(heights.find(b.second));
            curr = *heights.rbegin();//Notice that rbegin does not refer to the same element as end, but to the element right before it.
            cout<<curr<<endl;
            if(curr != prev)//the height is different, turning point {
                results.push_back({b.first, curr}); 
                prev = curr;
            }
        }
        return results;
    }
};
//Internally, multiset containers keep their elements ordered from lower to higher, therefore rbegin returns the element with the highest key value in the container.
