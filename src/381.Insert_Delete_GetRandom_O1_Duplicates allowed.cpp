class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto res = m.find(val) == m.end();
        m[val].push_back(nums.size());
        nums.push_back({ val, m[val].size() - 1});
        return res; //can't return early
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end())
            return false;
        auto last = nums.back();
        m[last.first][last.second] = m[val].back(); //modify m of last, index in nums
        nums[m[val].back()] = last; //modify nums of val
        m[val].pop_back();
        if (m[val].empty())
            m.erase(val);
        nums.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        int n = nums.size();
        return n == 0 ? -1 : nums[rand() % n].first;
    }

    unordered_map<int, vector<int>> m; //value, index that are of the same value
    vector<pair<int, int>> nums; //value, index in vector of m[val], 0, 1, 2
};

/**
* Your RandomizedCollection object will be instantiated and called as such:
* RandomizedCollection obj = new RandomizedCollection();
* bool param_1 = obj.insert(val);
* bool param_2 = obj.remove(val);
* int param_3 = obj.getRandom();
*/
