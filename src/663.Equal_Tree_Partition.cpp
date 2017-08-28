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
    int helper(TreeNode* root, unordered_map<int, int>& m) {//sum, freq
        if(!root)
            return 0;
        int sum = root->val + helper(root->left, m) + helper(root->right, m);
        m[sum]++;
        return sum;
    }
    bool checkEqualTree(TreeNode* root) {
        unordered_map<int, int> m;
        int sum = helper(root, m);
        if(sum%2 != 0)
            return false;
        if(sum == 0)
            return  m[sum] > 1; //special case since 0/2 = 0
        return m.find(sum/2) != m.end();
    }
};

//[0,-1,1] set is not enough! 0 is special case!
