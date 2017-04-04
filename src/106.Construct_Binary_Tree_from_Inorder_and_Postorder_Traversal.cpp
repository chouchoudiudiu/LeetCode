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
    TreeNode* helper (vector<int>& postorder, vector<int>& inorder,
        int postStart, int inStart, int len) {
        if (len == 0) 
            return NULL; //return condition
        int rootVal = postorder[postStart + len - 1]; //basically the last item
        auto index = find(inorder.begin(), inorder.end(), rootVal) - inorder.begin();
        TreeNode* root = new TreeNode(rootVal);
        int leftLen = index - inStart, rightLen = len - leftLen - 1;
        root->left = helper(postorder, inorder, postStart, inStart, leftLen);
        root->right = helper(postorder, inorder, postStart + leftLen, index + 1, rightLen);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty() || inorder.empty() || postorder.size() != inorder.size())
            return NULL;
        return helper (postorder, inorder, 0, 0, postorder.size());
    }
};
