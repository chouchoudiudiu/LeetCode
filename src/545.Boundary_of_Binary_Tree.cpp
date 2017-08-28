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
    void printLeftEdges(TreeNode* root, bool print, vector<int>& res) {
        if(!root)
            return;
        if(print || (!root->left && !root->right))
            res.push_back(root->val);
        printLeftEdges(root->left, print, res);
        printLeftEdges(root->right, print && !root->left, res);
    }
    void printRightEdges(TreeNode* root, bool print, vector<int>& res) {
        if(!root)
            return;
        printRightEdges(root->left, print && !root->right, res);
        printRightEdges(root->right, print, res);
        if(print || (!root->left && !root->right))
            res.push_back(root->val);
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        res.push_back(root->val);
        printLeftEdges(root->left, true, res);
        printRightEdges(root->right, true, res);
        return res;
    }
};
