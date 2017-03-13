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
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX, prev = -1;
        helper(root, prev, minDiff);
        return minDiff == INT_MAX ? 0 : minDiff;
    }
    void helper(TreeNode* root, int& prev, int& minDiff) 
    {
        if(!root)  return;
        helper(root->left, prev, minDiff);
        if(prev != -1)
            minDiff = min(minDiff, root->val - prev);
        prev = root->val;
        helper(root->right, prev, minDiff);
    }
};
