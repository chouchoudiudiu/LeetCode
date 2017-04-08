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
    ListNode* getMidPoint(ListNode* head) {
        if (!head) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    void reverse(ListNode*& head) {
        if (!head) return;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;
        ListNode* mid = getMidPoint(head);
        ListNode* secondHead = mid->next;
        mid->next = NULL;
        
        //reverse second half
        reverse(secondHead);
        //interleave two halves, the second half is always shorter
        ListNode* l1 = head;
        ListNode* l2 = secondHead;
        ListNode* l1Next = l1->next;
        ListNode* l2Next = l2->next;
        while (l2) {//shorter
            l1Next = l1->next;
            l2Next = l2->next;
            l1->next = l2;
            l2->next = l1Next;
            l1 = l1Next;
            l2 = l2Next;
        }
    
        return;
    }
};
