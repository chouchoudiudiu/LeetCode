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
    void inorder(TreeNode* root, int& i, int k, int& ret) {
        if (!root)
            return;
        
        inorder(root->left, i, k, ret);
        i = i + 1;
        if (i == k)
            ret = root->val;
        inorder(root->right, i, k, ret);
    }
    int kthSmallest(TreeNode* root, int k) {
        int i = 0, ret = -1;
        inorder(root, i, k, ret);
        return ret;
    }
};
