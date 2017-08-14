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
    void dfs(TreeNode* root, vector<int>& res, int depth) {
        if (!root)
            return;
        if (depth == res.size())
            res.push_back(root->val);
        dfs(root->right, res, depth + 1);
        dfs(root->left, res, depth + 1); //if showing left side view, put left and then right
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, res, 0);
        return res;
    }
};


/////
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                auto p = q.front();
                q.pop();
                if(i == 0) //first element
                    res.push_back(p->val);
                if(p->right)
                    q.push(p->right);
                if(p->left)
                    q.push(p->left);
            }
        }
        return res;
    }
};
//put right node first
//can be easily done using dfs actually
