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
    bool inorder(TreeNode* root, TreeNode*& prev) {
        if(!root)
            return true;
        if (!inorder(root->left, prev))
            return false;
        if (prev && root->val <= prev->val) //strictly increasing
            return false;
        prev = root;
        if (!inorder(root->right, prev))
            return false;
        return true;
    }

    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return inorder(root, prev);
    }
};
