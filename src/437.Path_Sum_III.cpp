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
    int dfs(TreeNode* root, int sum) {//dfs means select root, keep going
        if (!root)
            return 0;
        return (root->val == sum) + dfs(root->left, sum - root->val) + dfs(root->right, sum - root->val);
    }
    
    int pathSum(TreeNode* root, int sum) {
        if (!root)
            return 0;
        return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};
