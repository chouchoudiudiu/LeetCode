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
    ListNode* reverseBetween(ListNode* head, int m, int n) {//1,2,3,4,5 [2,4]
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = dummy;
        int i = 1;
        while (++i <= m) 
            curr = curr->next;
        ListNode* last = curr; //1
        ListNode* prev = curr->next, *tail = curr->next;//2
        curr = prev->next;
        for (int i = m; i < n; ++i) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        tail->next = curr; //2->next = 5
        last->next = prev; //1->next = 4
        return dummy->next;
    }
};
