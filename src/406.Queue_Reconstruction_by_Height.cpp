class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);// higher in front
        }; //don't forget ";"
        sort(people.begin(), people.end(), comp);
        vector<pair<int, int>> res;
        for (auto p : people) {
            res.insert(res.begin() + p.second, p);
        }
        return res;
    }
};

/*
We first sort the people to make them stand from the highest to shortest. For people with same height, sort them according to the count of people before them from small to big.
Then, we use the way similar to insert sorting to reorder the people. For a given person to insert, all the people already sorted are higher, so we just insert him in the "right" place to make the people before him as his "count" indicates. Since he is shorter than all the people in the sorted list, the "count" of the "existing" people does not be broken by the insertion.
*/
