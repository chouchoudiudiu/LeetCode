class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        stk.push({0, INT_MAX});
    }
    
    void push(int x) {
        stk.push({x, min(stk.top().second, x)});
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
    
    stack<pair<int, int>> stk;
};

//may have many different way to write it

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
