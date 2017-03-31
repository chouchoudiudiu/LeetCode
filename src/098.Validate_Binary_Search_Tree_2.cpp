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
    bool helper (TreeNode* root, bool hasLowerBound, int lowerBound, bool hasUpperBound, int upperBound) {
        if(!root)
            return true;
        if (hasLowerBound && root->val <= lowerBound)
            return false;
        if (hasUpperBound && root->val >= upperBound)
            return false;
        return helper (root->left, hasLowerBound, lowerBound, true, root->val) &&
               helper (root->right, true, root->val, hasUpperBound, upperBound);
    }

    bool isValidBST(TreeNode* root) {
        return helper (root, false, 0, false, 0); //values doesn't matter, can use min/max too
    }
};
