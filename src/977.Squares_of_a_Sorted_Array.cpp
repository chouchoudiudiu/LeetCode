class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
  		vector<int> res;
  		int n = A.size(), left = 0, right = n - 1;
  		while(left <= right) {
  			if(abs(A[left]) <= abs(A[right])) {
  				res.push_back(A[right]*A[right]);
  				--right;
  			}
  			else{
  				res.push_back(A[left]*A[left]);
  				++left;
  			}
  		}
  		return vector(res.rbegin(), res.rend()); //reverse
    }
};
