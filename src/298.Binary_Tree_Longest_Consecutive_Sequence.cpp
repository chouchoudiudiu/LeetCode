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
    int search(TreeNode* root, TreeNode* parent, int len) {
        if (!root)
            return 0;
        if (parent && root->val == parent->val + 1)
            len += 1;
        else
            len = 1;
        return max(len, max(search(root->left, root, len), search(root->right, root, len))); //3个中最大长度，可以继续，可以以该节点新开始
    }

    int longestConsecutive(TreeNode* root) {
        return search(root, NULL, 0);
    }
};
