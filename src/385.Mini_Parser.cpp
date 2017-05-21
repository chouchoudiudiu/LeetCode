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
    NestedInteger deserialize(string s) {
        stack<NestedInteger> stk;
        stk.push(NestedInteger());//后面有top的操作简单些
        int i = 0, sign = 1;
        while (i < s.length()) {
            int val = 0;
            bool hasDigits = false;
            while (isdigit(s[i])) {
                val = val*10 + s[i++] - '0';
                hasDigits = true;
            }
            if (hasDigits) {
                stk.top().add(NestedInteger(sign * val));
                sign = 1;
            }
            if (s[i] == '[')
                stk.push(NestedInteger());
            if (s[i] == ']') {
                auto ni = stk.top();
                stk.pop();
                stk.top().add(ni); //接到上一层list的后面, like dummy () in the beginning if [x]
            }
            if (s[i] == '-')
                sign = -1;
            ++i;
        }
        return stk.top().getList().back(); //stk.top() has [] ; back is okay too? single element in vector
    }
};
/*
At the very beginning, an empty NestedInteger is placed in the stack. This NestedInteger will be regarded as a list that holds one but only one NestedInteger, which will be returned in the end.
Logic: When encountering '[', the stack has one more element. When encountering ']', the stack has one less element.
*/
