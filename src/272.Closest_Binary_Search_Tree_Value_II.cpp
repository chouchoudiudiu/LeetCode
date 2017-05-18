/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //should have faster solutions.
class Solution {
public:
    void inorder(TreeNode* root, double target, int k, vector<int>& res) {
        if (!root)
            return;
        inorder(root->left, target, k, res);
        if (res.size() < k) res.push_back(root->val); //not very good, the numbers might be close to end
        else if (abs(root->val - target) < abs(res[0] - target)) {
            res.erase(res.begin());
            res.push_back(root->val);//replace
        }
        else
            return; //gap is enlarging, the later numbers will be further away from target, early terminate!
        inorder(root->right, target, k, res);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        inorder(root, target, k, res);
        return res;
    }
};
