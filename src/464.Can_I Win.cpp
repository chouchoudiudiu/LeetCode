class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal)
            return true; //直接取
        if (maxChoosableInteger*(maxChoosableInteger + 1)/2 < desiredTotal)
            return false;
        unordered_map<int, bool> m;
        return helper(maxChoosableInteger, desiredTotal, 0, m);
    }
    
    bool helper(int max, int total, int used, unordered_map<int, bool>& m) {
        if (m.count(used))
            return m[used];
        for (int i = 1; i <= max; ++i) {
            int cur = (1<<i);
            if ((cur & used) == 0) {
                if (total <= i || !helper(max, total - i, cur | used, m)) {
                    m[used] = true; 
                    return true;
                }
            }
        }
        m[used] = false;
        return false;
    }
};
//vector<bool> used(maxChoosableInteger + 1, false); failed on 10, 40 not sure why
//10...40
//3...4
