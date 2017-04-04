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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size(); //make sure the size is pre-calculated, otherwise in loop the q size will change
            vector<int> level;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                level.push_back(node->val);
                q.pop();
                if (node->left) 
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            res.insert(res.begin(), level); //insert from the beginning
        }
        return res;
    }
};
