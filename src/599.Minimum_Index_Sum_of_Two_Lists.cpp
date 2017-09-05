class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        unordered_map<string, int> m; //string and index
        int minIdxSum = INT_MAX;
        for(int i = 0; i < list1.size(); ++i)
            m[list1[i]] = i;
        for(int j = 0; j < list2.size(); ++j) {
            if(m.count(list2[j])) {
                int i = m[list2[j]];
                if(minIdxSum > i + j) {
                    res.clear();
                    res.push_back(list2[j]);
                    minIdxSum = i + j;
                }
                else if(minIdxSum == i + j)
                    res.push_back(list2[j]);
            }
        }
        return res;
    }
};

//You could assume there always exists an answer.
