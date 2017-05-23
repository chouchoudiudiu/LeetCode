class Solution {
public:
//almost copied...
    int findKthNumber(int n, int k) {
        int curr = 1;
        k = k - 1;
        while (k > 0) {
            int steps = getSteps (n, curr, curr + 1);
            if (steps <= k) {
                curr += 1;
                k -= steps; 
            }
            else {
                curr *= 10; //curr * 10 is always next preorder node
                k -= 1;
            }
        }
        return curr;
    }
    
    int getSteps (int n, long n1, long n2) {
        int steps = 0;
        while (n1 <= n) {
	        steps += min(long(n + 1), n2) - n1;   //17 - 10 + 1 = 8
            n1 *= 10;
            n2 *= 10;
        }    

    return steps;
}
};
