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
    void reverseRecursive(ListNode*& p) {
        if (!p || !p->next)
            return;
        ListNode* res = p->next;
        reverseRecursive(res);
        p->next->next = p; //original res 1->2->3: 2->next = 1
        p->next = NULL;
        p = res;
    }
    ListNode* reverseList(ListNode* head) {
        reverseRecursive(head);
        return head;
    }
};

//////////////

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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
