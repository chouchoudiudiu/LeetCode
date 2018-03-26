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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* pab = headA;
        ListNode* pba = headB;
        for (; pab != pba;) {
            pab = pab ? pab->next : headB; //go to the other linkedlist
            pba = pba ? pba->next : headA;
        }
        return pab;
    }
/*令两个指针pab先访问第一个链表再访问第二个链表, pba先访问第二个链表，再访问第一个链表。因此两个访问序列的尾部重合。只要检测两者是否相等就好。*/
};

/////////////////////////////

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        int len1 = 0, len2 = 0;
        while(p1) {
            ++len1;
            p1 = p1->next;
        }
        while(p2) {
            ++len2;
            p2 = p2->next;
        }
        int diff = max(len1, len2) - min(len1, len2);
        p1 = headA, p2 = headB;
        while(--diff >= 0) {
            if(len1 > len2)
                p1 = p1->next;
            else
                p2 = p2->next;
        }
        while(p1 && p2) {
            if(p1 == p2)
                return p1;
            p1 = p1->next;
            p2 = p2->next;
        }  
        return NULL;
    }
};
