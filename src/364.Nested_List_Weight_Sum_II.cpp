/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:   
    void helper(vector<NestedInteger>& nestedList, int depth, vector<int>& sums) {
        if (depth == sums.size()) //start a new level
            sums.push_back(0);
        for (auto v : nestedList) {
            if (v.isInteger())
                sums[depth] += v.getInteger();
            else 
                helper(v.getList(), depth + 1, sums);
        }
    }
    
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<int> sums;
        helper (nestedList, 0, sums);
        
        int res = 0;
        for (int i = 0; i < sums.size(); ++i) {
            res += sums[i] * (sums.size() - i);
        }
        return res;
    }
};
