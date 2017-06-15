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


class Solution {
public:
    void inorder(TreeNode* root, TreeNode*& res, TreeNode* p, TreeNode*& prev) {
        if(!root)
            return;
        inorder(root->left, res, p, prev);
        if(prev == p) 
            res = root; //奇怪的是如果直接return的话会有错
        prev = root;
        inorder(root->right, res, p, prev);
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* res = NULL, *prev = NULL;
        inorder(root, res, p, prev);
        return res;
    }
};
