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
    int helper(TreeNode* root, int& lMax, int& rMax) {
        if(!root)
            return 0;
        int ll = 0, lr = 0, rl = 0, rr = 0;
        lMax = helper(root->left, ll, lr);
        rMax = helper(root->right, rl, rr);
        return max(lMax + rMax, ll + lr + rl + rr + root->val);// the latter allows to use root
    }
    
    int rob(TreeNode* root) {
        int lMax = 0, rMax = 0;
        return helper(root, lMax, rMax);//max for left and right child 
    }
};
