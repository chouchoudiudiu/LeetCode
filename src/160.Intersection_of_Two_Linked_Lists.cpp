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
        if (!headA || !headB)
            return NULL;
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
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int len1 = 0, len2 = 0;
    ListNode* p = headA;
    ListNode* q = headB;
    while (p) {
        ++len1;
        p = p->next;
    }
    while (q) {
        ++len2;
        q = q->next;
    }
    p = headA;
    q = headB;
    if (len1 > len2) {
        int count = len1 - len2;
        while (count-- > 0) 
            p = p->next;
    }
    else
    {
        int count = len2 - len1;
            while(count-- > 0)
                q = q->next;
    }
    while (p && q) {
        if (p == q)
            return p;
        p = p->next;
        q = q->next;
    }
    return NULL;
}
};
