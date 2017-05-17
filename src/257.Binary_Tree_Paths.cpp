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
    void helper(TreeNode* root, vector<int> path, vector<string>& res) {
        if (!root)
            return;
        path.push_back(root->val);
        if (!root->left && !root->right) {
            string s;
            for (int i = 0; i < path.size() - 1; ++i)
                s += to_string(path[i]) + "->";
            s += to_string(path[path.size() - 1]);
            res.push_back(s);
            return;
        }
        helper(root->left, path, res);
        helper(root->right, path, res);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root)
            return {};
        vector<string> res;
        vector<int> path;
        helper(root, path, res);
        return res;
    }
};
