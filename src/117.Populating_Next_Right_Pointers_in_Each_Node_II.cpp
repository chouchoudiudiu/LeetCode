/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)
            return;
        TreeLinkNode* curr = root, *head = NULL, *tail = NULL; //head and tail are for next level
        while (curr) {
            if (curr->left) {
                if (head == NULL) {
                    head = tail = curr->left; //tail may be real, can have only one item
                }
                else {
                    tail->next = curr->left;
                    tail = tail->next;
                }
            }
            if (curr->right) {
                if (head == NULL) {
                    head = tail = curr->right;
                }
                else {
                    tail->next = curr->right;//connect one by one
                    tail = tail->next;
                }
            }
            curr = curr->next;
            if (curr == NULL) {//end of a level, go to next level
                curr = head;
                head = tail = NULL;
            }
        }
    }
};
