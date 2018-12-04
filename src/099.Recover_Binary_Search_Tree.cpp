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
    void inorder(TreeNode* root, TreeNode*& last, TreeNode*& node1, TreeNode*& node2)
    {
        if(!root)
            return;
        inorder(root->left, last, node1, node2);
        if(!node1 && last->val > root->val) {
            node1 = last;
        }
        if (last->val > root->val) {
            node2 = root; //keep updating node2
        }
        last = root;
        inorder(root->right, last, node1, node2);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* node1 = nullptr; //the first node smaller than previous node
        TreeNode* node2 = nullptr; //the second node smaller than previous node
        TreeNode* last = new TreeNode(INT_MIN); //always record the last node
        inorder(root, last, node1, node2);
        swap(node1->val, node2->val); // note not swap(node1, node2) or (*node1, *node2)... 
    }
};

////

void inorder(TreeNode* root, TreeNode*& last, TreeNode*& node1, TreeNode*& node2) {
        if(!root)
            return;
        inorder(root->left, last, node1, node2);
        if(root->val < last->val) {
            if(!node1) {
                node1 = last;
                node2 = root;
            }
            else 
                node2 = root;
        }
        last = root;
        inorder(root->right, last, node1, node2);
    }
