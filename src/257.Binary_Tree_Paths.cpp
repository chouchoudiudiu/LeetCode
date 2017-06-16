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


class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result;
        vector<int> path;
        stack< pair<TreeNode*, int> > s;
        s.push(make_pair(root, 0));
        while (!s.empty()) {
            int level = s.top().second;
            path.resize(level);
            TreeNode * node = s.top().first;
            s.pop();
            path.push_back(node->val);
            //if (!node->left && !node->right) 
            //{
                string pathstr;
                for (int i = 0; i < path.size(); ++i) {
                    pathstr += to_string(path[i]) + ((i != path.size() - 1) ? "->" : "");
                }
                result.push_back(pathstr);
            //} else {
                if (node->right) s.push(make_pair(node->right, level + 1));
                if (node->left) s.push(make_pair(node->left, level + 1));
            //}
        }
        return result;
    }
};
