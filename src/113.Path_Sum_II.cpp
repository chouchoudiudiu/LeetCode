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
    void helper(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& res) {//modify, faster, need to pop
        if (!root)
            return;
        
        path.push_back(root->val);
        if (!root->left && !root->right && root->val == sum) {
            res.push_back(path);
            //return; //need to pop in the end
        }
        helper(root->left, sum - root->val, path, res);
        helper(root->right, sum - root->val, path, res);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (!root)
            return res;
        vector<int> path;
        helper (root, sum, path, res);
        return res;
    }
};
