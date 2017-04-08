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
    ListNode* insertionSortList(ListNode* head) {
        if (!head)  return NULL;
        ListNode* dummy = new ListNode(-1);
        ListNode* next = head; //not dummy->next
        while (next) {//take each node out one by one
            ListNode* node = next;
            next = node->next;
            ListNode* prev = dummy;
            ListNode* curr = dummy->next;
            //find insert location
            while (curr && curr->val < node->val) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = node;
            node->next = curr;
        }
        return dummy->next;
    }
};
