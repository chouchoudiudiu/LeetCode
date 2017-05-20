class HitCounter {
public://circular array?
    /** Initialize your data structure here. */
    HitCounter() {
        times.resize(300);
        hits.resize(300);
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int idx = timestamp%300;
        if (times[idx] != timestamp) { //a new 300 interval
            times[idx] = timestamp;
            hits[idx] = 1;
        }
        else
            ++hits[idx];
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int res = 0;
        for (int i = 0; i < 300; ++i) {
            if (timestamp - times[i] < 300)
                res += hits[i];
        }
        return res;
    }
    
    vector<int> times, hits; //times记载时间戳
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
 /*
 由于Follow up中说每秒中会有很多点击，下面这种方法就比较巧妙了，定义了两个大小为300的一维数组times和hits，分别用来保存时间戳和点击数，在点击函数中，将时间戳对300取余，然后看此位置中之前保存的时间戳和当前的时间戳是否一样，一样说明是同一个时间戳，那么对应的点击数自增1，如果不一样，说明已经过了五分钟了，那么将对应的点击数重置为1。那么在返回点击数时，我们需要遍历times数组，找出所有在5分中内的位置，然后把hits中对应位置的点击数都加起来即可，*/
