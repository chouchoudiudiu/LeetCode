/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
//DFS, seems slower than BFS
    void dfs(TreeNode* root, int depth, vector<vector<int>>& res) {
        if (!root)  return;
        if (depth == res.size()) 
            res.push_back(vector<int>()); //start a new level
        res[depth].push_back(root->val);
        dfs(root->left, depth + 1, res);
        dfs(root->right, depth + 1, res);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        dfs(root, 0, res);
        return res;
    }
};
