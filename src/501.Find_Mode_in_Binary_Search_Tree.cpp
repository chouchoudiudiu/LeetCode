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
    void inorder(TreeNode* root, TreeNode*& prev, int& max, int& cnt, vector<int>& res) {
        if(!root)
            return;
        inorder(root->left, prev, max, cnt, res);
        if(prev) {
            if(root->val == prev->val)
                ++cnt;
            else
                cnt = 1;
        }
        if(cnt > max) {
            res.clear();
            res.push_back(root->val);
            max = cnt;
        }
        else if(cnt == max) //note it is else if!
            res.push_back(root->val);
        prev = root;
        inorder(root->right, prev, max, cnt, res);
    }
    vector<int> findMode(TreeNode* root) {
        if(!root)
            return {};
        vector<int> res;
        TreeNode* prev = NULL;
        int max = INT_MIN, cnt = 1; //MAX = 0 IS OKAY TOO
        inorder(root, prev, max, cnt, res);
        return res;
    }
};
