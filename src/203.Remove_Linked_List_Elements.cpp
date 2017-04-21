/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        ListNode* curr = head;
        while (curr) {
            if (curr->val != val) {
                prev->next = curr;
                prev = curr;
            }
            curr = curr->next;
        }
        prev->next = NULL; //last node
        return dummy->next;
    }
};
