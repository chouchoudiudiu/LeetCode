class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sz = size;
        sum = 0;
    }
    
    double next(int val) {
        if(q.size() < sz) {
            q.push(val);
            sum += val;
        }
        else {
            sum = sum - q.front() + val;
            q.pop();
            q.push(val);
        }
        return (double)sum/q.size(); //(double)
    }
    
    queue<int> q;
    long sum;
    int sz;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sz = size;
        sum = 0.0;
    }
    
    double next(int val) {
        q.push(val);
        sum += val;
        if(q.size() > sz) { //at most one, no need to while
            sum -= q.front();
            q.pop();
        }
        return sum/q.size();
    }
    
    int sz;
    double sum;
    queue<int> q;
};
