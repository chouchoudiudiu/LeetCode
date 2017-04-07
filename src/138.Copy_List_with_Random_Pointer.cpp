/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)  return NULL;
        unordered_map<RandomListNode*, RandomListNode*> m;
        RandomListNode* curr = head;
        while (curr) {
            m[curr] = new RandomListNode(curr->label);
            curr = curr->next;
        }
        curr = head;
        while (curr) {//copy next and random
            if (curr->next)
                m[curr]->next = m[curr->next];
            if (curr->random)
                m[curr]->random = m[curr->random];
            curr = curr->next;
        }
        return m[head];
    }
};
