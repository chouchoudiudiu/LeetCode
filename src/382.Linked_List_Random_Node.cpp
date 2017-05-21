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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res = head->val;
        ListNode* node = head->next;
        for (int i = 2; node; ++i) {
            int j = rand()%i;
            if (j == 0)
                res = node->val;
            node = node->next;
        }
        return res;
    }
    
    ListNode* head;
};
/*https://rosona.github.io/post/20151223/ 浅谈流处理算法 (1) – 蓄水池采样
1/(i-1) * (1-1/i) = 1/i   前 i-1轮中选中它的概率 1/(i - 1), (1 - 1/i) 第i轮不选i(用i替换前者)的概率，即保持原抽中者的概率
*/
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
