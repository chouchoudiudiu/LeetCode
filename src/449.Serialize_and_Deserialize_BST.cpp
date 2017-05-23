/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //how different is it from the binary one???
class Codec {
public:
    void serialize(TreeNode* root, ostringstream& oss) {
        if (!root) 
            oss<<"# "; //lc是用level order,更省空间？
        else {
            oss<<root->val<<" ";
            serialize(root->left, oss);
            serialize(root->right, oss);
        }
    }
    TreeNode* deserialize(istringstream &iss) {
        string val;
        iss>>val;
        if (val != "#") {
            TreeNode* root = new TreeNode(stoi(val));
            root->left = deserialize(iss);
            root->right = deserialize(iss);
            return root;
        }
        else 
            return NULL;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;
        serialize(root, oss);
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserialize(iss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
