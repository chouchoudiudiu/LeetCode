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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode *p1 = l1, *p2 = l2; //not to change l1, l2
        while (p1) {
            s1.push(p1->val);
            p1 = p1->next;
        }
        while (p2) {
            s2.push(p2->val);
            p2 = p2->next;
        }
        int carry = 0;
        ListNode* head = NULL;
        while (!s1.empty() || !s2.empty() || carry > 0) {
            int sum = carry;
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            ListNode* node = new ListNode(sum%10);
            carry = sum/10;
            if (head == NULL)
                head = node;
            else { //insert from front
                node->next = head;
                head = node;
            }
        }
        return head;
    }
};

/// 一开始那里。。。没有必要
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while(l1) {
           s1.push(l1->val);
           l1 = l1->next; 
        }
        while(l2) {
           s2.push(l2->val);
           l2 = l2->next; 
        }
        int carry = 0;
        ListNode* head = NULL;
        while(!s1.empty() || !s2.empty() || carry > 0) {
            int sum = carry;
            if(!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            ListNode* node = new ListNode(sum%10);
            carry = sum/10;
            if(!head)
                head = node;
            else {
                node->next = head;
                head = node;
            }
        }
        return head;
    }
};
