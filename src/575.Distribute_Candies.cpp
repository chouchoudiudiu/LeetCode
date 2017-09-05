class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> m(candies.begin(), candies.end());
        return min(m.size(), candies.size()/2);
    }
};

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        size_t kinds = 1;
        sort(candies.begin(), candies.end());
        for(size_t i = 1; i < candies.size(); ++i) 
            kinds += candies[i] != candies[i - 1];
        return min(kinds, candies.size()/2);
    }
};
