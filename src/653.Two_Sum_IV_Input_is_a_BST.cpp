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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> m;
        return helper(root, k, m);
    }
    bool helper(TreeNode* root, int k, unordered_set<int>& m) {
        if(!root)
            return false;
        if(m.find(k - root->val) != m.end())
            return true;
        m.insert(root->val);
        return helper(root->left, k, m) || helper(root->right, k, m);
    }
};

//should have better solutions that use the property of bst
