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
    TreeNode* str2tree(string s) {
        if(s.size() == 0)
            return NULL;
        int val = 0, i = 0;
        if(s[0] == '-') {
            ++i;
        }
        while(isdigit(s[i])) {
            i++;
        }
        int leftC = 0, rightC = 0, leftStart = i;
        while(i < s.size()) {
            if(s[i] == '(')
                ++leftC;
            if(s[i] == ')')
                ++rightC;
            if(leftC == rightC)
                break;
            ++i;
        }
        string left = leftC == 0 ? "" : s.substr(leftStart + 1, i - leftStart - 1);
        string right = (i == s.size() - 1 || leftC == 0) ?  "" :s.substr(i + 2, s.size() - 1 - i - 2);
        TreeNode* root = new TreeNode(stoi(s.substr(0, leftStart)));
        root->left = str2tree(left);
        root->right = str2tree(right);
        return root;
    }
};
//"-4(2(3)(1))(6(5)(7))"
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
    TreeNode* str2tree(string s) {
        int i = 0;
        return s.size() == 0 ? NULL : build(s, i);
    }

private:
    TreeNode* build(string s, int& i) {
        int start = i;
        if (s[i] == '-') {
            i++;
        }
        while (isdigit(s[i])) {
            i++;
        }
        int num = stoi(s.substr(start, i - start));
        TreeNode* node = new TreeNode(num);
        if (s[i] == '(') {
            node->left = build(s, ++i);
            i++;    // )
        }
        if (s[i] == '(') {
            node->right = build(s, ++i);
            i++;    // )
        }
        return node;
    }
};
//"-4(2(3)(1))(6(5)(7))"
