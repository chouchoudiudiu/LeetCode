class Solution {
public:
    int findKthElement(int A[], int m, int B[], int n, int k)
    {
        if (m > n)
            return findKthElement(B, n, A, m, k);
        if (m == 0)
            return B[k-1];
        if (k == 1)
            return min(A[0], B[0]);
        int pa = min(m, k/2);
        int pb = k - pa;
        if (A[pa - 1] < B[pb - 1])
            return findKthElement(A + pa, m - pa, B, pb, k - pa ); //eliminate a few; (1,2),7,8,9 3,6,9,12,18,22
        else 
            return findKthElement(A, pa, B + pb, n - pb, k - pb );
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m == 0) return n%2 ? nums2[n/2] : (nums2[n/2 - 1] + nums2[n/2])/2.0;//index base 0
        if (n == 0) return m%2 ? nums1[m/2] : (nums1[m/2 - 1] + nums1[m/2])/2.0;
        int total = m + n;
        if (total % 2)
            return findKthElement(&nums1[0], m, &nums2[0], n, total/2 + 1); //the kth element, index base 1
        else
            return (findKthElement(&nums1[0], m, &nums2[0], n, total/2) +  findKthElement(&nums1[0], m, &nums2[0], n, total/2 + 1))/2.0;
    }
};
//[]
//[1]
