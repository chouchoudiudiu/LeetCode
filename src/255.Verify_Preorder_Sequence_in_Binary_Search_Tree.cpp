class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT_MIN;
        stack<int> stk;
        for (auto v : preorder) {
            if (v < low)
                return false;
            while (!stk.empty() && v > stk.top()) {
                low = stk.top();
                stk.pop();
            }
            stk.push(v);
        }

        return true; //stk is not empty in the end
    }
};

//{5, 2, 1, 3, 6}
//碰到3,则它可能是1或者2的右子树，结果是2的右子树，更新low为2，因为3可能有子树，它的子树必须大于2
/*其先序遍历的结果是{5, 2, 1, 3, 6}, 我们先设一个最小值low，然后遍历数组，如果当前值小于这个最小值low，
返回false，对于根节点，我们将其压入栈中，然后往后遍历，如果遇到的数字比栈顶元素小，说明是其左子树的点，
继续压入栈中，直到遇到的数字比栈顶元素大，那么就是右边的值了，我们需要找到是哪个节点的右子树，
所以我们更新low值并删掉栈顶元素，然后继续和下一个栈顶元素比较，如果还是大于，则继续更新low值和删掉栈顶，
直到栈为空或者当前栈顶元素大于当前值停止，压入当前值，这样如果遍历完整个数组之前都没有返回false的话，最后返回true即可*/
关键在于找到是谁的右子树。找到了之后就要track新遇到的点有没有小于这个Root，右子树的结点值是不可以小于这个root （即Low值）
 
////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT_MIN;
        int i = -1;
        for (auto v : preorder) {
            if (v < low)
                return false;
            while (i >= 0 && v > preorder[i])
                low = preorder[i--];
            preorder[++i] = v;
        }

        return true; //stk is not empty in the end
    }
};

///////////////////////////////////////////////////////////////////////////////////////
//backtracking: slow
class Solution {
public:
    bool helper(vector<int>& preorder, int start, int end, int min, int max) {
        if (start > end)
            return true;
        int rootVal = preorder[start];
        if (rootVal >= max || rootVal <= min) //in bad range
            return false;
        int rightStart = start + 1;
        while (rightStart <= end && preorder[rightStart] < rootVal)
            ++rightStart;
        return helper(preorder, start + 1, rightStart - 1, min, rootVal) &&
               helper(preorder, rightStart, end, rootVal, max);
    }
    bool verifyPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size() - 1, INT_MIN, INT_MAX);
    }
};

//{5, 2, 1, 3, 6}
//碰到3,则它可能是1或者2的右子树，结果是2的右子树，更新low为2，因为3可能有子树，它的子树必须大于2
/*
keeping a stack of nodes (just their values) of which we're still in the left subtree. If the next number is smaller than the last stack value, then we're still in the left subtree of all stack nodes, so just push the new one onto the stack. But before that, pop all smaller ancestor values, as we must now be in their right subtrees (or even further, in the right subtree of an ancestor). Also, use the popped values as a lower bound, since being in their right subtree means we must never come across a smaller number anymore.
*/
