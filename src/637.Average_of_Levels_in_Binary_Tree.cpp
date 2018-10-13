class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        if(!root)
            return res;
        q.push(root);
        while(!q.empty()) {
            long sum = 0; //必须是long, 不可int
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                sum += node->val; //be careful with round
            }
            res.push_back((double)sum/(double)sz); //必须是double, 不可float
        }
        return res;
    }
};
