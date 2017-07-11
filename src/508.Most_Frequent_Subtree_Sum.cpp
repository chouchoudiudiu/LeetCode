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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> m;//subtree sum; freq
        int maxFreq = 0;
        vector<int> res;
        helper(root, maxFreq, m);
        for(auto v : m) {
            if(v.second == maxFreq)
                res.push_back(v.first);
        }
        return res;
    }
    int helper(TreeNode* root, int& maxFreq, unordered_map<int, int>& m) {
        if(!root)
            return 0;
        int sum = root->val;
        sum += helper(root->left, maxFreq, m);
        sum += helper(root->right, maxFreq, m);
        m[sum]++;
        if(m[sum] > maxFreq)
            maxFreq = m[sum];
        return sum;
    }
};
