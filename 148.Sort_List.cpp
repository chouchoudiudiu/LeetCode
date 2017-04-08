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
    ListNode* getMidPoint(ListNode* head) {
        if (!head)
            return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) { //fast->next->next
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;// if odd, mid; if even, 0123, return 1
    } 
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return NULL;
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                prev->next = l1;
                prev = l1;
                l1 = l1->next;
            }
            else {
                prev->next = l2;
                prev = l2;
                l2 = l2->next;
            }
        }
        if (l1)
            prev->next = l1;
        if (l2)
            prev->next = l2;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head; //head->next, direct return
        ListNode* mid = getMidPoint(head);
        ListNode* secondHead = mid->next;
        mid->next = NULL;
        return merge(sortList(head), sortList(secondHead));
    }
}; 
