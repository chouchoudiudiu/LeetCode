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
//一个树的根节点的Right先存起来，先求左边的flatten结果，记录最后访问的节点last，求好之后根的right为左子节点，last的右子节点为根的原//右子节点, 接着求右子树的flatten结果，因为root不变，自然的接到了last后面
    void flatten(TreeNode* root) {
        TreeNode* last = NULL;
        helper(root, last);
    }
    void helper(TreeNode* root, TreeNode*& last) {
        if (!root)
            return;
        last = root; //PREORDER
        TreeNode* right = root->right;
        helper(root->left, last);
        root->right = root->left;
        root->left = NULL;//CLOSE
        last->right = right;
        helper(root->right, last); //感觉应该是right, last. 两个都可以通过OJ
    }
};
