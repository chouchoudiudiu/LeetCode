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
        if(s.length() == 0)
            return NULL;
        int i = 0;
        if(s[0] == '-') {
            ++i;
        }
        while(isdigit(s[i])) 
            i++;
        int leftC = 0, rightC = 0, leftStart = i; //leftC means left ( count; right C means right ) count.
        while(i < s.length()) {
            if(s[i] == '(')
                ++leftC;
            if(s[i] == ')')
                ++rightC;
            if(leftC == rightC)
                break;
            ++i;   
        }
        string left = leftC == 0 ? "" : s.substr(leftStart + 1, i - leftStart - 1);
        string right = (i >= s.length() - 1) ? "" : s.substr(i + 2, s.length() - 1 - i - 2);
        TreeNode* root = new TreeNode(stoi(s.substr(0, leftStart)));
        root->left = str2tree(left);
        root->right = str2tree(right);
        return root;
    }
};

//|| leftC == 0 can be modified as (i >= s.length() - 1) ; > includes the case with all numbers!
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
