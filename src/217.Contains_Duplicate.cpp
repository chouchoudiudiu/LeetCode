class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto v : nums) {
            if (++m[v] > 1)
                return true;
        }
        return false;
    }
};

// return set<int>(nums.begin(), nums.end()).size() < nums.size();


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> m;
        for(auto v : nums) {
            if(m.find(v) != m.end())
                return true;
            m.insert(v);
        }
        return false;
    }
};
