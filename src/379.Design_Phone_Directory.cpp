class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; ++i) {
            q.push(i);
            m[i] = true;
        } 
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (!q.empty()) {
            int val = q.front();
            q.pop();
            m[val] = false;//not available
            return val;
        }
        return -1;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return m[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (m[number] == false) { //otherwise non op
            m[number] = true;
            q.push(number);
        }
    }
    
    queue<int> q;
    unordered_map<int, bool> m;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
