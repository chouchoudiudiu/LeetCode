unsigned int nextPowerOf2(unsigned int n)
{
    unsigned count = 0;
 
    /* First n in the below condition is for the case where n is 0*/
    if (n && !(n&(n-1)))
        return n;
 
    while( n != 0)
    {
        n >>= 1;
        count += 1;
    }
 
    return 1<<count;
}

class NumArray {
public:
	NumArray(vector<int> &nums) {
		N = nextPowerOf2(nums.size()); //13->16
		segTree.resize(N << 1, 0);//16->32
		copy(nums.begin(), nums.end(), segTree.begin() + N);
		for (int i = N - 1; i > 0; --i)
			segTree[i] = segTree[i << 1] + segTree[i << 1 | 1];//left, right child
	}

	void update(int i, int val) { //modified to be consistent with 2D version
	    int diff = val - segTree[N + i];
        for (int k = N + i; k > 0; k >>= 1) 
            segTree[k] += diff;
	}

	int sumRange(int i, int j) {
		//query
		int sum = 0;
		for (i += N, j += N + 1; i < j; i >>= 1, j >>= 1) //j += N + 1
		{
			if (i & 1) sum += segTree[i++];         //the right child of left bound, include; i++
			if (j & 1) sum += segTree[--j];        //the right child of right bound + 1, actually left of, include; j--
		}
		return sum;
	}
    
    vector<int> segTree;
    int N;//next power of 2 of n
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

//http://codeforces.com/blog/entry/18051?
