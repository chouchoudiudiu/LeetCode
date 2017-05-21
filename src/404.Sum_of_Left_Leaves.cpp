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
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }
    int helper(TreeNode* root, bool isLeft) {
        if (!root)
            return 0;
        if (!root->left && !root->right) 
            return isLeft ? root->val : 0;
        int sum = 0;
        sum += helper(root->left, true);
        sum += helper(root->right, false);
        return sum;
    }
};
