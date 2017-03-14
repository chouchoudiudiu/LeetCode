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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        while (l1 || l2 || carry > 0)
        {
            sum = (l1?l1->val : 0) + (l2?l2->val : 0) + carry;    
            ListNode* node = new ListNode(sum%10);
            carry = sum/10;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;       
            p->next = node;
            p = node;
        }
        return dummy->next;
    }
};
