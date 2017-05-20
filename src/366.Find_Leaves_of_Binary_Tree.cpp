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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, res);
        return res;
    }
    
    int helper(TreeNode* root, vector<vector<int>>& res) {
        if (!root)
            return -1; //-1!
        int depth = 1 + max(helper(root->left, res), helper(root->right, res));//左右子节点中较大值加1为当前节点的深度值
        if (depth == res.size()) { // a new depth starts
            res.push_back(vector<int>()); //no new, just vector<int>()
        }
        res[depth].push_back(root->val);
        return depth;
    }
};
