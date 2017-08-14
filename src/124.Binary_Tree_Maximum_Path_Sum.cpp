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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        helper(root, maxSum);
        return maxSum;
    }
    int helper(TreeNode* root, int& maxSum) {
        if (!root)
            return 0;
        int l = max(0, helper(root->left, maxSum));
        int r = max(0, helper(root->right, maxSum));
        maxSum = max(maxSum, l + r + root->val); //l + r + root->val is localmax
        return root->val + max(l, r); 
        //maxSum是包括左右两边以及根节点的最大值，l, r及ret的值，只是左半边+root,或者右半边+root, 为了后期拼接
    }
};
