class Solution {
public:
    int maxDepth(Node* root) {
        if(!root)
            return 0;
        vector<int> heights;
        for(auto v : root->children) 
            heights.push_back(maxDepth(v));
        return heights.empty() ? 1 : *max_element(heights.begin(), heights.end()) + 1;
    } //heights.empty() means no children!
};
