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

    int minDepth(TreeNode* root) {
        if (!root)  
            return 0;
        if (!root->left)
            return minDepth(root->right) + 1;
        if (!root->right)
            return minDepth(root->left) + 1;
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

=======
    
   class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if(!root->left)
            return right + 1;
        if(!root->right)
            return left + 1;
        return min(left, right) + 1;
    }
};  
