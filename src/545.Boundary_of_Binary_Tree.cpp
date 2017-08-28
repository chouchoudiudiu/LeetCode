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
        printLeftEdges(root->right, print && !root->left, res); //note
    }
    void printRightEdges(TreeNode* root, bool print, vector<int>& res) {
        if(!root)
            return;
        printRightEdges(root->left, print && !root->right, res);
        printRightEdges(root->right, print, res);
        if(print || (!root->left && !root->right))
            res.push_back(root->val); //post order!!!!!!!!!!!!
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

//http://articles.leetcode.com/print-edge-nodes-boundary-of-binary/
//shouldn't make the assumption that all left-most nodes could only be reached by following each node’s left branch (similar for right-most nodes).
