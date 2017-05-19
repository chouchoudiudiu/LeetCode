class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sz = size;
        sum = 0;
    }
    
    double next(int val) {
        if (q.size() < sz) {
            sum += val;
            q.push(val);
            return (double)sum/q.size(); //double
        }
        else {
            sum -= q.front();
            q.pop();
            q.push(val);
            sum += val;
            return (double)sum/sz; //double
        }
    }
    
    queue<int> q;
    int sz;
    long sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
