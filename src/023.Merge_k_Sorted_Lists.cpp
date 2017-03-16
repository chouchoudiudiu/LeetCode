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
    struct comp {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) //not null
                pq.push(lists[i]);//head of each list
        }
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            dummy->next = node;
            dummy = node;
            if (node->next) //check not null
                pq.push(node->next);
        }
        
        return head->next;
    }
};
