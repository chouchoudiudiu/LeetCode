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
        if(!root)
            return;
        TreeLinkNode* curr = root, *head = NULL, *tail = NULL, *lastTail = root; //for next level
        while(curr) {
            if(curr->left) {
                if(!head) 
                    head = tail = curr->left; //first node
                else {
                    tail->next = curr->left;
                    tail = tail->next;
                }
            }
            if(curr->right) {
                if(!head) 
                    head = tail = curr->right; //first node
                else {
                    tail->next = curr->right;
                    tail = tail->next;
                }
            }
            curr = curr->next;
            if(!curr) { //go to the next level
                lastTail->next = head;
                lastTail = tail;
                curr = head;
                head = tail = NULL;
            }
        }
    }
};
