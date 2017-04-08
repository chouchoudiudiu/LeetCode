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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* prev = root;
        while (!stk.empty()) {
            TreeNode* curr = stk.top();
            if ( (!curr->left && !curr->right) || (curr->left == prev) || (curr->right == prev)) {//孩子若2个一定在它之前visited，因同时入
                res.push_back(curr->val);
                stk.pop();
                prev = curr;
            }
            else {
                if (curr->right) stk.push(curr->right);
                if (curr->left) stk.push(curr->left);
            }
        }
        return res;
    }
};

//当一个节点值被取出来时，它的左右子节点要么不存在，要么已经被访问过了
/*     the top node is a leaf node (no left&right children), pop it.
          or if the top node has been visited, pop it. (here we use a sign head to show the latest popped node, if the top node's child = the latest popped node, either left or right, it must has been visited.)*/
