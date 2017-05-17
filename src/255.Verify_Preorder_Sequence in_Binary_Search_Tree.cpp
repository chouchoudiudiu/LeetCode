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
