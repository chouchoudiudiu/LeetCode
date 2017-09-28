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


O(N) iterative
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!p || !root)
            return NULL;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        bool found = false;
        while(!stk.empty() || node) {
            if(node) {
                stk.push(node);
                node = node->left;
            }
            else {
                TreeNode* q = stk.top();
                stk.pop();
                if(found)
                    return q;
                if(q == p)
                    found = true;
                node = q->right;
                if(node) {
                    stk.push(node);
                    node = node->left;
                }
            }
        }
        return NULL;
    }
};


/////
class Solution {
public:
    bool inorder(TreeNode* root, TreeNode*& res, TreeNode* p, TreeNode*& prev) {
        if(!root)
            return false;
        if(inorder(root->left, res, p, prev))
            return true;
        if(prev == p) {
            res = root; //奇怪的是如果直接return的话会有错
            return true;
        }
        prev = root;
        if(inorder(root->right, res, p, prev))
            return true;
        return false;
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* res = NULL, *prev = NULL;
        inorder(root, res, p, prev);
        return res;
    }
};
