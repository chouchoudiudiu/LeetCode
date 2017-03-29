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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        while (prev->next) {
            ListNode* curr = prev->next;
            while (curr->next && curr->val == curr->next->val)
                curr = curr->next; // the last duplicate (if any)
            if (curr != prev->next) //means there was duplicate
                prev->next = curr->next;
            else
                prev = curr; //same as prev = prev->next;
            
        }
        
        return dummy->next;
    }
};
