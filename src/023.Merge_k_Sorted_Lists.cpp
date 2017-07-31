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
        bool operator()(const ListNode* a, const ListNode* b) {
            return a->val > b->val;      
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> pq; //minheap
        ListNode* dummy = new ListNode(0);
        ListNode* node = dummy;
        for(auto l : lists) {
            if(l) 
                pq.push(l);
        }
        while(!pq.empty()) {
            ListNode* tmp = pq.top();
            pq.pop();
            node->next = tmp;
            node = node->next;
            if(tmp->next) {
                pq.push(tmp->next);
                tmp = tmp->next;
            }
        }
        return dummy->next;
    }
};
