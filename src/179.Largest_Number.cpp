bool smaller(int n1, int n2) {//who comes first in the sorted array?, s1
    string s1 = to_string(n1) + to_string(n2);
    string s2 = to_string(n2) + to_string(n1);
    return stoll(s1) > stoll(s2);
}
    
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string s(""); //return
        sort(nums.begin(), nums.end(), smaller);
        if (nums[0] == 0) //ok to be in the middle
            return "0";
        for (auto v : nums) {
            s += to_string(v);
        }
        return s;
    }
};
//[0,0]
