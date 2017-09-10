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
    void helper(TreeNode* root, int prev, int len, int& res) {
        if(!root)
            return;
        if(root->val == prev + 1)
            ++len;
        else
            len = 1;
        res = max(res, len);
        helper(root->left, root->val, len, res);
        helper(root->right, root->val, len, res);
        //3个中最大长度，可以继续，可以以该节点新开始, res放最后也可以
    }
    int longestConsecutive(TreeNode* root) {
        if(!root)
            return 0;
        int res = 0;
        helper(root, root->val, 0, res); //len表示到当前节点结束的local max, root可能为空，所以先设成0
        return res;
    }
};
//preorder from parent to child

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
