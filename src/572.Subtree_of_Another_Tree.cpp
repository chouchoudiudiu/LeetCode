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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s)
            return false;
        if(isSame(s, t))
            return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    
    bool isSame(TreeNode* p, TreeNode* q) {
        if(!p && !q) 
            return true;
        if(!p || !q)
            return false;
        if(p->val != q->val)
            return false;
        return isSame(p->left, q->left) && isSame(p->right, q->right);
    }
};
/*
[1,2,3]
[1,2]
*/
//For each node during pre-order traversal of s, use a recursive function isSame to validate if sub-tree started with this node is the same with t.
