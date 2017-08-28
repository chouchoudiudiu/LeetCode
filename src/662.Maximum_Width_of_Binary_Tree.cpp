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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int maxWidth = 0;
        queue<pair<TreeNode*, int>> q; //node and id
        q.push({root, 1});
        while(!q.empty()) {
            int sz = q.size();
            int l = q.front().second, r = l; //right starts same as left
            for(int i = 0; i < sz; ++i) {
                TreeNode* node = q.front().first;
                r = q.front().second;
                q.pop();
                if(node->left)
                    q.push({node->left, r*2});
                if(node->right)
                    q.push({node->right, r*2 + 1});
                
            }
            maxWidth = max(maxWidth, r - l + 1);
        }
        
        return maxWidth;
    }
};
