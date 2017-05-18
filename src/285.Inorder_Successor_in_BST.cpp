/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//O(logn)
//search from root to bottom, find the smallest node larger than p and return the last one that was larger.
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p)
            return NULL;
        if (root->val <= p->val) 
            return inorderSuccessor(root->right, p);
        else {
            TreeNode* left = inorderSuccessor(root->left, p);
            return left ? left : root;
        }
    }
};

/*
    TreeNode* predessor(TreeNode* root, TreeNode* p) {
        if (!root || !p)
            return NULL;
        if (root->val >= p->val) 
            return inorderSuccessor(root->left, p);
        else {
            TreeNode* right = inorderSuccessor(root->right, p);
            return right ? right : root;
        }
    }
*/


///////////////////////////////////////////////////////////

//search from root to bottom, find the smallest node larger than p and return the last one that was larger.
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p)
            return NULL;
        TreeNode* succ = NULL;
        while (root) {
            if (root->val <= p->val)
                root = root->right;
            else {
                succ = root;
                root = root->left;
            }
        }
        return succ;
    }
};
