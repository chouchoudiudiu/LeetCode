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
    TreeNode* helper (vector<int>& preorder, vector<int>& inorder,
        int preStart, int inStart, int len) {
        if (len == 0) 
            return NULL; //return condition
        int rootVal = preorder[preStart];
        auto index = find(inorder.begin(), inorder.end(), rootVal) - inorder.begin();
        TreeNode* root = new TreeNode(rootVal);
        int leftLen = index - inStart, rightLen = len - leftLen - 1;
        root->left = helper(preorder, inorder, preStart + 1, inStart, leftLen);
        root->right = helper(preorder, inorder, preStart + leftLen + 1, index + 1, rightLen);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size())
            return NULL;
        return helper (preorder, inorder, 0, 0, preorder.size());
    }
};
