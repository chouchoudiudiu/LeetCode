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
    TreeNode* helper(vector<int>& nums, int low, int high) {
        if (low > high)
            return NULL;
        int mid = low + (high - low)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, low, mid - 1);
        root->right = helper(nums, mid + 1, high);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};

//两种均可，一种是向左倾斜，一种是向右倾斜
