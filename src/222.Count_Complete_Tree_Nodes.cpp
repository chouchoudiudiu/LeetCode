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
    int getTreeHeight(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + getTreeHeight(root->left);//lean left
    }
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int lh = getTreeHeight(root->left);
        int rh = getTreeHeight(root->right);
        if (lh == rh) //left is full, right may or may not
            return pow(2, lh) + countNodes(root->right);
        else //right is full, left may or may not
            return pow(2, rh) + countNodes(root->left);
    }
};
