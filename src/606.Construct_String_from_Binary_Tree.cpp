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
    string tree2str(TreeNode* t) {
        if(!t)
            return "";
        string s = to_string(t->val);
        if(!t->left && t->right)
            s += "()";
        if(t->left)
            s += '(' + tree2str(t->left) + ')';
        if(t->right)
            s += '(' + tree2str(t->right) + ')';
        return s;
    }
};

//preorder, if leaf, no need to add, if left child is empty while right is not, need to add (), otherwise 
