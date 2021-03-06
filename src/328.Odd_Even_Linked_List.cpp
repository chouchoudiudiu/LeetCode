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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* odd = head, *evenHead = head->next, *even = evenHead;
        while (even && even->next) { //even (actually odd->next) && even->next two ->next should be valid since the ->next->next
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next; 
            even = even->next;
        }
        
        odd->next = evenHead;
        return head;
    }
};
