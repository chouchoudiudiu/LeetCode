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
//need to pay special attention to empty left or right subtrees
//bottom up
    bool isValidBST(TreeNode* root, long& mn, long& mx, int& cnt) {
        if (!root) 
            return true;
        int left_n = 0, right_n = 0;
        long left_mn = LONG_MIN, left_mx = LONG_MAX, right_mn = LONG_MIN, right_mx = LONG_MAX;
        bool isLeft = isValidBST(root->left, left_mn, left_mx, left_n);
        bool isRight = isValidBST(root->right, right_mn, right_mx, right_n);
        
        if (isLeft && isRight) { //further check root
            if ((!root->left || root->val > left_mx) && (!root->right || root->val < right_mn)) {
                cnt = left_n + right_n + 1;
                mn = root->left ? left_mn : root->val; 
                mx = root->right ? right_mx : root->val;
                return true;
            }
        }
        //no else here, otherwise may not getting cnt value if not satisfying inner if
        cnt = max(left_n, right_n);
        return false;
    }
    int largestBSTSubtree(TreeNode* root) {
        int cnt = 0;
        long mn = LONG_MIN, mx = LONG_MAX;
        isValidBST(root, mn, mx, cnt);
        return cnt;
    }
};

//O(n)
