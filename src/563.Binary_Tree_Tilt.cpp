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
    int findTilt(TreeNode* root) {
        int tilt = 0;
        postOrder(root, tilt);
        return tilt;
    }
    
    int postOrder(TreeNode* root, int& tilt) {
        if(!root)
            return 0;
        int leftSum = postOrder(root->left, tilt);
        int rightSum = postOrder(root->right, tilt);
        tilt += abs(leftSum - rightSum);
        return leftSum + rightSum + root->val;
    }
};
