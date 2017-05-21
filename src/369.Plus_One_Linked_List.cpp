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
    int helper (ListNode* head) { //return carry
        if (!head) //such that carry will be 1 if reaches the last digit
            return 1;
        int carry = helper(head->next);
        if (carry == 0)
            return 0;
        int val = head->val + 1; //has carry from next
        head->val = val%10;
        return val/10;
    }
    
    ListNode* plusOne(ListNode* head) {
        if (helper(head) == 0) //non empty
            return head;
        else {
            ListNode* newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        }
    }
};
