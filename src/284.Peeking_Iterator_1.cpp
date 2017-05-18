// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    flag = false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (!flag) {
            val = Iterator::next();
            flag = true;
        }
        return val;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (!flag)
	        return Iterator::next();
	    else {
	        flag = false;
	        return val;
	    }
	}

	bool hasNext() const {
	    if (!flag)
	        return Iterator::hasNext();
	    else
	        return true; //peeked already!
	}
	
	int val;
	bool flag;//advanced already
};
//Follow up: How would you extend your design to be generic and work with all types, not just integer?
//note: Iterator(*this) makes a copy of current iterator, then call next on the copied iterator object to get the next value //without affecting current iterator.
