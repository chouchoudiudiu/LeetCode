class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end())
            return false;
        m.insert({val, nums.size()}); 
        nums.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {//O(1) no need to move too much
        if (m.find(val) == m.end())
            return false;
        int n = nums.size(), idx = m[val];
        if (idx != n - 1) { //swap when necessary
            //m.insert({ nums[n - 1], idx });
            m[nums[n - 1]] = idx;
            swap(nums[idx], nums[n - 1]);
        }
        m.erase(val);
        nums.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int n = nums.size();
        return n == 0 ? -1 : nums[rand() % n];
    }

    unordered_map<int, int> m; //value, index
    vector<int> nums;
};

/**
* Your RandomizedSet object will be instantiated and called as such:
* RandomizedSet obj = new RandomizedSet();
* bool param_1 = obj.insert(val);
* bool param_2 = obj.remove(val);
* int param_3 = obj.getRandom();
*/
