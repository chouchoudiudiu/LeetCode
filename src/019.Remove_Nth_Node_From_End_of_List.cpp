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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        int i = 0;
        while (i++ < n) {
            fast = fast->next;
        }
        if (!fast) //if the node to be deleted is the head, special process, including n == 1 case
            return head->next; 
        while (slow->next && fast->next) {// condition
            slow = slow->next;
            fast = fast->next;
        }
        //slow finds the node one ahead of the desired node
        slow->next = slow->next->next;
        return head;
    }
};

//[1,2] 2
