unsigned int nextPowerOf2(unsigned int n)
{
    unsigned count = 0;
 
    /* First n in the below condition is for the case where n is 0*/
    if (n && !(n&(n-1)))
        return n;
 
    while( n != 0)
    {
        n  >>= 1;
        count += 1;
    }
 
    return 1<<count;
}

class NumMatrix {
public:
	NumMatrix(vector<vector<int>> &matrix) :
		M(nextPowerOf2(matrix.size())), //13->16
			N(matrix.size() ? nextPowerOf2(matrix[0].size()) : 0), //13->16
			tree(M * 2, vector<int>(N * 2, 0)) {
		for (int i = 0; i < matrix.size(); ++i) {
			//copy a row of matrix to tree
			copy(matrix[i].begin(), matrix[i].end(), tree[M + i].begin() + N);
			//compute bottom-left part of tree matrix
			for (int j = N - 1; j > 0; --j)
				tree[M + i][j] = tree[M + i][j << 1] + tree[M + i][j << 1 | 1];
		}
		//compute top part of the tree matrix
		for (int i = M - 1; i > 0; --i)
			for (int j = N * 2 - 1; j > 0; --j)
				tree[i][j] = tree[i << 1][j] + tree[i << 1 | 1][j];
	}

	void update(int row, int col, int val) {
		int diff = val - tree[M + row][N + col];
		// update all ancestors of node 
		for (int k = M + row; k > 0; k >>= 1) {
			for (int j = N + col; j >0; j >>= 1) {
				tree[k][j] += diff;
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		int sum = 0;
		//sum over row ranges
		for (row1 += M, row2 += M + 1; row1 < row2; row1 >>= 1, row2 >>= 1) {
			if (row1 & 1) sum += sumRow(row1++, col1, col2);
			if (row2 & 1) sum += sumRow(--row2, col1, col2);
		}
		return sum;
	}

	inline int sumRow(int i, int col1, int col2) { //sum over column ranges
		vector<int>& t = tree[i];
		int sum = 0;
		for (col1 += N, col2 += N + 1; col1 < col2; col1 >>= 1, col2 >>= 1) //j += N + 1
		{
			if (col1 & 1) sum += t[col1++];         //the right child of left bound, include; i++
			if (col2 & 1) sum += t[--col2];        //the right child of right bound + 1, actually left of, include; j--
		}
		return sum;
	}

	const int M, N; //half of tree matrix size
	vector<vector<int>> tree; //2D tree matrix
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
