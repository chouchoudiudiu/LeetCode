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
//上往下开始翻转，直至翻转到最左子节点
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* prev = NULL;
        TreeNode* next = NULL; 
        TreeNode* tmp = NULL; //to store the right child from parent (curr)
        while (curr) {
            next = curr->left; //2
            curr->left = tmp; //from previous level, NULL
            tmp = curr->right; //3
            curr->right = prev; //NULL
            prev = curr; //1
            curr = next; //2...in next loop: 2->left = 3 2->right = 1;
        }
        return prev; //the last visited node
    }
};
