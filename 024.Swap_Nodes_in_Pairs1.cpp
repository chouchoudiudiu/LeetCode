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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy; // to use next
        ListNode* curr = head;
        while (curr && curr->next) {
            ListNode* nextStart = curr->next->next; //mark 3
            curr->next->next = curr; //2->1
            prev->next = curr->next; //0->2
            curr->next = nextStart; //1->3, otherwise curr->next will still be 2
            prev = curr; //prev = 1, end of last node
            curr = nextStart;
        }
        
        if (curr) //left
            prev->next = curr;
        return dummy->next;
    }
};

