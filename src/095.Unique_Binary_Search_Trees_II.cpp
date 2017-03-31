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
    vector<TreeNode*> dfs(int left, int right) {
        vector<TreeNode*> subtree;
        if (left > right) {
            subtree.push_back(NULL);
            return subtree;
        }
        for (int i = left; i <= right; ++i) { //i is root
            vector<TreeNode*> leftSubtree = dfs(left, i - 1);
            vector<TreeNode*> rightSubtree = dfs(i + 1, right);
            for (auto l : leftSubtree)
                for (auto r : rightSubtree) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    subtree.push_back(root);
                }
        }
        return subtree;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n <= 0)
            return res;
        return dfs(1, n);
    }
};

/*
0
Output:
[[]]
*/
