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
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        while (root) {
            //update closest
            closest = abs(root->val - target) < abs(closest - target) ? root->val : closest;
            if (closest == target) //best possible found
                return closest;
            root = root->val > target ? root->left : root->right;
        }
        return closest;
    }
};

class Solution {
public:
    void helper(TreeNode* root, int& closest, double target) {
        if (!root)  return;
        if (abs(root->val - target) < abs(closest - target))
            closest = root->val;
        if (root->val > target) 
            helper(root->left, closest, target);
        if (root->val < target)
            helper(root->right, closest, target);
    }
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        helper(root, closest, target);
        return closest;
    }
};
