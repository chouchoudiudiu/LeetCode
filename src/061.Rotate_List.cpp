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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0)
            return head;
        int cnt = 1;
        ListNode* p = head, *q = head;
        while (p->next) { //get the last node
            p = p->next;
            ++cnt;
        }
        int newk = k%cnt;
        int i = 0;
        while (++i < cnt - newk) {
            q = q->next;
        }
        p->next = head;
        head = q->next;
        q->next = NULL;
        
        return head;
    }
};
