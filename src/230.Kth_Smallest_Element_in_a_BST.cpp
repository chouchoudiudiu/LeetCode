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
    void inorder(TreeNode* root, int& i, int k, int& ret) {
        if (!root)
            return;
        
        inorder(root->left, i, k, ret);
        i = i + 1;
        if (i == k)
            ret = root->val;
        inorder(root->right, i, k, ret);
    }
    int kthSmallest(TreeNode* root, int k) {
        int i = 0, ret = -1;
        inorder(root, i, k, ret);
        return ret;
    }
};



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
    int kthSmallest(TreeNode* root, int k) {
        int cnt = countNodes(root->left);
        if(cnt >= k)
            return kthSmallest(root->left, k);
        else if(k > cnt + 1)
            return kthSmallest(root->right, k - cnt - 1);
        return root->val; //k == cnt + 1
    }
    
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

//followup?
