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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root || !root->left)
            return root;
        TreeNode* l = root->left, *r = root->right;
        TreeNode* res = upsideDownBinaryTree(l);
        l->left = r;
        l->right = root;
        root->left = NULL;
        root->right = NULL;
        return res;
    }
};

/*
对于一个根节点来说，我们的目标是将其左子节点变为根节点，右子节点变为左子节点，原根节点变为右子节点，那么我们首先判断这个根节点是否存在，且其有
没有左子节点，如果不满足这两个条件的话，直接返回即可，不需要翻转操作。那么我们不停的对左子节点调用递归函数，直到到达最左子节点开始翻转，翻转好
最左子节点后，开始回到上一个左子节点继续翻转即可，直至翻转完整棵树
*/
