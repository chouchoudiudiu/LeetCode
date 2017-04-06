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
//preorder
    void dfs(TreeNode* root, int pathSum, int& totalSum) {
        if (!root)
            return;
        pathSum = pathSum*10 + root->val;
        if (!root->left && !root->right) {
            totalSum += pathSum;
            return;
        }
        dfs(root->left, pathSum, totalSum);// 不可int& pathSum,否则在遍历left child, pathsum改成12再right, 123
        dfs(root->right, pathSum, totalSum);
    }
    int sumNumbers(TreeNode* root) {
        int pathSum = 0, totalSum = 0;
        dfs(root, pathSum, totalSum);
        return totalSum;
    }
};
