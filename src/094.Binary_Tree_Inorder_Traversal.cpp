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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while (!stk.empty() || node) {
            if (node) {
                stk.push(node);
                node = node->left;
            }
            else {
                node = stk.top();
                res.push_back(node->val);
                stk.pop();
                node = node->right; //pop出来的元素如果有右子树,接着访问右子树,看它是否有左孩子,若有,下一个应为它的最左孩子
            }
        }
        return res;
    }
};
