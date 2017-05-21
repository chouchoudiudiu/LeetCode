class Solution {
public:
    Solution(vector<int> nums) {
        data = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return data;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = data;
        for (int i = res.size() - 1; i > 0; --i) {
            int j = rand()%(i + 1);
            swap(res[i], res[j]);
        }
        return res;
    }
    
    vector<int> data;
};
/*Use Fisher Yates algorithm to randomize.  
http://www.geeksforgeeks.org/shuffle-a-given-array/
case1:n个数中选中其他n-1个数字中的一个(不是最后一个，假设index为3)，将最后一个元素放到3位置，再将位置3处的这个最后元素移到n-2位置处
case2:n个数中选任意其他n-1中的一个到最后一个位置，最后一个位置排好后，左边剩余n-1个数中选中了i，放在n-2位置处
*/
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
