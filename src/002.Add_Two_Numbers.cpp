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
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode* dummy = new ListNode(0);
        ListNode* node = dummy;
        int carry = 0;
        while(l1 || l2 || carry) {
            int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            node->next = new ListNode(sum%10);
            node = node->next;
            carry = sum/10;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        return dummy->next;
    }
};
