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
    bool isUnivalSubtree(TreeNode* root, int& count) {
        if (!root)
            return true;
        bool isLeft = isUnivalSubtree(root->left, count);
        bool isRight = isUnivalSubtree(root->right, count);
        if (isLeft && isRight && 
            (!root->left || root->left->val == root->val) &&
            (!root->right || root->right->val == root->val) ) { //child要么没有，有就要相等
                ++count;
                return true;
            }
        else
            return false;
    }
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        isUnivalSubtree(root, count);
        return count;
    }
};
