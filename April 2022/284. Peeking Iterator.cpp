class PeekingIterator : public Iterator {
public:
    int nextVal;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        nextVal = Iterator::next();
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return nextVal;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int temp = nextVal;
        if (Iterator::hasNext())
            nextVal = Iterator::next();
        else
            nextVal = NULL;
	    return temp;
	}
	
	bool hasNext() const {
	    return (nextVal != NULL);
	}
};