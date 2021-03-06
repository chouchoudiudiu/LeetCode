class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& output, vector<int>& candidates, int start, int sum, int target) {
        if (sum == target) {
            res.push_back(output);
            return;
        }   
        if (sum > target)   return;
        for (int i = start; i < candidates.size() && candidates[i] <= target; ++i) {
            output.push_back(candidates[i]);
            dfs(res, output, candidates, i, sum + candidates[i], target); //i: each can be used more than once
            output.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> output;
        sort(candidates.begin(), candidates.end()); //good to stop early
        dfs(res, output, candidates, 0, 0, target); //index, current sum
        return res;
    }
};
//这种类型题目如果是求某种target能否达到，i(可复用)或 i + 1(不可复用); 如果是那种最后由length决定的，start+1
//input (C) (without duplicates) , such that dfs here will not generate duplicate results
