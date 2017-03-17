/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution { //tried many times...
public:
    ListNode* reverseOneGroup(ListNode* prev, ListNode* next) { // -1 1 2 3 4 -> -1 and 4
        ListNode* last = prev->next;
        ListNode* curr = last->next;
        while (curr != next) {
            last->next = curr->next; //1->3
            curr->next = prev->next; //2->1->3
            prev->next = curr; //-1->2->1->3
            curr = last->next; //curr = 3
        }
        return last; // 1
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1)    
            return head;
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy, *curr = head;
        dummy->next = head;
        int i = 0;
        while (curr)
        {
            if(++i %k == 0) {
                prev = reverseOneGroup(prev, curr->next);
                curr = prev->next; //new group
            }
            else {
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};
