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
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }
    int helper(TreeNode* root, bool isLeft) {
        if(!root)
            return 0;
        int sum = 0;
        if(!root->left && !root->right && isLeft)
            sum += root->val;
        sum += helper(root->left, true);
        sum += helper(root->right, false);
        return sum;
    }
};

/////////////////////////
//BFS
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sumleft = 0;
        if(!root)
            return 0;
        queue<pair<TreeNode*, bool>> q;
        q.push({root, false});
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                auto p = q.front();
                q.pop();
                if(!p.first->left && !p.first->right && p.second) //leaf, left, not necessarily the first one!
                    sumleft += p.first->val;
                if(p.first->left)
                    q.push({p.first->left, true});
                if(p.first->right)
                    q.push({p.first->right, false});
            }
        }
        return sumleft;
    }
};

//[1] expected 0
