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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(0);
        ListNode* dummy2 = new ListNode(0);
        ListNode* p = dummy1, *q = dummy2;
        ListNode* curr = head;
        while(curr) {
            if (curr->val < x) {
                p->next = curr;
                p = p->next;
            }
            else {
                q->next = curr;
                q = q->next;
            }
            curr = curr->next;
        }
        q->next = NULL; //!important
        p->next = dummy2->next;
        return dummy1->next;
    }
};
