class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> steps;//key: stone[i]具体Pos unit; value, 到达它曾经所用的步骤
        steps[0].insert(0); //从某处到0跳了0步
        for (auto pos : stones) {
            if (steps.count(pos) == 0) {
                continue;
            }
            for (auto it = steps[pos].begin(); it != steps[pos].end(); ++it) {//假定pos可达，从pos再往后走可以到那些地方呢
                if (*it > 1) 
                    steps[pos + *it - 1].insert(*it - 1);
                steps[pos + *it].insert(*it);
                steps[pos + *it + 1].insert(*it + 1);
            }
        }
        return steps.count(stones.back());
        // return !steps[stones.back()].empty();  // check if the last position is reachable
    }
};
