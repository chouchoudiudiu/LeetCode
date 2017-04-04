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
//bottom up O(n) O(n)
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
    
    int checkHeight(TreeNode* root) {
        if (!root)  return 0;
        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1)   return -1;
        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1)   return -1;
        if (abs(leftHeight - rightHeight) > 1)
            return -1;
        return max(leftHeight, rightHeight) + 1;
    }
};

/*
//top-down O(nlogn)
    int getHeight(TreeNode *node) {
        if(!node) 
            return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    };
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        if (abs(getHeight(root->left) - getHeight(root->right)) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    */
