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
    int diameterOfBinaryTree(TreeNode* root) {
        int longest = 0;
        helper(root, longest);
        return longest;
    }
    
    int helper(TreeNode* root, int& longest) {
        if(!root)
            return 0;
        int left = helper(root->left, longest);
        int right = helper(root->right, longest);
        longest = max(longest, left + right); //count of edges, not node>
        return max(left, right) + 1;
    }
};//helper itself return the number of its path left only or right only
