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
    void reverse(ListNode*& head) {
        if (!head || !head->next) //actually not necessary here
            return;
        ListNode* prev = NULL, *curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;//new head!!!!
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        ListNode* slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* secondHalf = slow->next;
        slow->next = NULL;
        reverse(secondHalf);
        slow = head;
        while(secondHalf) {
            if (secondHalf->val != slow->val)
                return false;
            secondHalf = secondHalf->next;
            slow = slow->next;
        }
        return true;
    }
};
