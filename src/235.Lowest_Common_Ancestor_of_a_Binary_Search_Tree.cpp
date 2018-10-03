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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q)
            return NULL;
        if (root->val < min(p->val, q->val))
            return lowestCommonAncestor(root->right, p, q);
        else if (root->val > max(p->val, q->val))
            return lowestCommonAncestor(root->left, p, q);
        else
            return root;
    }
};

=======
    
    class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        int max_v = max(p->val, q->val), min_v = min(p->val, q->val);
        if(root->val > max_v)
            return lowestCommonAncestor(root->left, p, q);
        if(root->val <= max_v && root->val >= min_v)
            return root;
        if(root->val < min_v)
            return lowestCommonAncestor(root->right, p, q);
    }
};
