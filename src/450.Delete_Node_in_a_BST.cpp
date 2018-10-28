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
    TreeNode* getMin(TreeNode* node) {
        while (node->left)
            node = node->left;
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return NULL;
        if (root->val < key) {
            root->right = deleteNode(root->right, key); //note that it is not return deleteNode(root->right, key)....
        }
        else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        else { //exact key found!
            if (!root->left && !root->right)
                return NULL;
            else if (!root->left)
                return root->right;
            else if (!root->right)
                return root->left;
            else {
                TreeNode* node = getMin(root->right);//find the min value in right subtree(basically the leftmost child), replace the root value with its value
                root->val = node->val;
                root->right = deleteNode(root->right, node->val);
            }
        }
        return root;
    }
};
