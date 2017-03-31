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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> res;
       if (!root)   return res;
       stack<TreeNode*> currStk, nextStk;
       bool leftToRight = true;
       currStk.push(root);
       while (!currStk.empty()) {
           vector<int> level;
           int size = currStk.size(); //size need to be calculated first
           for (int i = 0; i < size; ++i) {
               TreeNode* node = currStk.top();
               level.push_back(node->val);
               currStk.pop();
               if (leftToRight) {
                   if (node->left) nextStk.push(node->left);
                   if (node->right) nextStk.push(node->right);
               }
               else {
                   if (node->right) nextStk.push(node->right);
                   if (node->left) nextStk.push(node->left);
               }
           }
           res.push_back(level);
           swap(currStk, nextStk);
           leftToRight = !leftToRight;
       }
       return res;
    }
};
