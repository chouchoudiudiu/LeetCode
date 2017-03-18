class Solution {
public:

    void dfs(vector<vector<int>>& res, vector<int>& output, vector<int>& candidates, int sum, int target, int start){
        if (sum > target)
            return;
        if (sum == target)
        {
            res.push_back(output);
            return;
        }
        for (int i = start; i < candidates.size() && candidates[i] <= target; ++i) { 
            if (i == start || candidates[i] != candidates[i - 1]) //not generating duplicate output
            {
                output.push_back(candidates[i]);
                dfs(res, output, candidates, sum + candidates[i], target, i + 1); //i: each can be used ONLY once
                output.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> output;
        sort(candidates.begin(), candidates.end());
        dfs(result, output, candidates, 0, target, 0);
        return result;
    }
};

/* if we can only use duplicated numbers once [10,1,2,7,6,1,2,2,2,5] 8
            if (candidates[i] == prev)
                continue;
            if (i == start || candidates[i] != candidates[i - 1]) //not generating duplicate output
            {
                output.push_back(candidates[i]);
                dfs(res, output, candidates, sum + candidates[i], target, i + 1, candidates[i]); //i: each can be used ONLY once
                output.pop_back();
            }
*/
