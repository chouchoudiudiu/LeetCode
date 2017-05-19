class Solution {
public:
 //keep track of the two minimals seen so far, if later we see a number larger than both, it is the a[k] we are looking for
    bool increasingTriplet(vector<int>& nums) {
        int n1 = INT_MAX, n2 = INT_MAX;
        for (auto v : nums) {
            if (v <= n1)
                n1 = v;
            else if (v <= n2) //n2 > n1 otherwise falls into first if
                n2 = v;
            else
                return true; //v > v2 > n1
        }
        return false;
    }
};

//[1,1,-2,6]
//[1,2,2,1]
//make sure <= 必须要严格大于，才会落入别的if/else
