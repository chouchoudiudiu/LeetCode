/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //BFS level order traversal
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        map<int, vector<int>> m; //map (key sorted), 从左到右，vertically, -3, -2, -1, 0, 1, 2, 3
        queue<pair<int, TreeNode*>> q; //verID
        q.push({0, root}); //center;
        while (!q.empty()) {
            int size = q.size();//size of this level
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front().second;
                int verID = q.front().first;
                q.pop();
                m[verID].push_back(node->val);
                if (node->left)
                    q.push({verID - 1, node->left});
                if (node->right)
                    q.push({verID + 1, node->right});
            }
        }
        for (auto v : m) {
            res.push_back(v.second); //v.second is a vector of int
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        map<int, vector<int>> m; //map (key sorted), 从左到右，vertically, -3, -2, -1, 0, 1, 2, 3 (verID, value)
        queue<pair<int, TreeNode*>> q; //verID
        q.push({0, root}); //center
        while(!q.empty()) {
            int verID = q.front().first;
            TreeNode* node = q.front().second;
            m[verID].push_back(node->val);
            q.pop();
            if(node->left)
                q.push({verID - 1, node->left});
            if(node->right)
                q.push({verID + 1, node->right});
        }
        
        for(auto v : m) {
            res.push_back(v.second); //v.second is a vector of int
        }
        return res;
    }
};
