class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> q;
        if(!root)
            return res;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            vector<int> row;
            for(int i = 0; i < sz; ++i) {
                Node* n = q.front();
                q.pop();
                row.push_back(n->val);
                for(auto v : n->children) 
                    q.push(v); //by default_not_null
            }
            res.push_back(row);
        }
        return res;
    }
};
