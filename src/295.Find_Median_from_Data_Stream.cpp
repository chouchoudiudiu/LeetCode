class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
         if(maxHeap.size() == minHeap.size()) {
             if (!maxHeap.empty() && num > minHeap.top()) {//num大于较大N个数中最小的, minheap中需要移动一个到maxheap中
                 maxHeap.push(minHeap.top());//10
                 minHeap.pop();
                 minHeap.push(num);//13
             }
             else 
                maxHeap.push(num);
         }
         else {//maxHeap.size() == minHeap.size() + 1, x should go to maxHeap
             if (num < maxHeap.top()) {//小于maxheap中的最大值
                 minHeap.push(maxHeap.top());
                 maxHeap.pop();
                 maxHeap.push(num);
             }
             else
                minHeap.push(num);//大于maxheap中的最大值，扔到minHeap中
         }
    }
    
    double findMedian() {
        if (maxHeap.empty())
            return 0;// so does minHeap
        if (maxHeap.size() == minHeap.size())
            return (double)(maxHeap.top() + minHeap.top())/2.0;
        else
            return maxHeap.top();
    }
    
    priority_queue<int, vector<int>, less<int>> maxHeap; //stl default
    priority_queue<int, vector<int>, greater<int>> minHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
 //may have simpler coding
 // maintain maxHeap.size >= minHeap.size, 
// maxHeap stores numbers less than median 最小的N或N+1个数，假设一共2*N 或 2*N + 1个数字
// if x <= min(maxHeap), x goes to maxHeap, otherwise x goes to minHeap (最大的N个数)
