class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        for (int i = 3; i < x.size(); ++i) {
            if (x[i] >= x[i - 2] && x[i - 3] >= x[i - 1])//i = 3: x0 >= x2; x3 >= x1
                return true;
            if (i >= 4 && x[i - 1] == x[i - 3] && x[i] >= x[i - 2] - x[i - 4])
                return true;
            if (i >= 5 && x[i - 2] >= x[i - 4] && x[i - 3] >= x[i - 1] &&
                x[i - 1] >= x[i - 3] - x[i - 5] && x[i] >= x[i - 2] - x[i - 4])
                return true;
        }
        return false;
    }
};

// Categorize the self-crossing scenarios, there are 3 of them: 
// 1. Fourth line crosses first line and works for fifth line crosses second line and so on...
// 2. Fifth line meets first line and works for the lines after
// 3. Sixth line crosses first line and works for the lines after
