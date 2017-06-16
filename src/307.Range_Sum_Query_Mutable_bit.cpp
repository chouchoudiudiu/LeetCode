class NumArray {
public:
    NumArray(vector<int> nums) {
        vec.resize(nums.size() + 1);
        bit.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            update(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        int diff = val - vec[i + 1];//vec real index starts from 1
        for (int j = i + 1; j < vec.size(); j += (j & (-j))) //所有上级
            bit[j] += diff;
        vec[i + 1] = val;
    }
    
    int sumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);
    }
    
    int getSum(int i) {//不包括nums[i], 最大到nums[i - 1]; vec则不同: index
        int res = 0;
        for (int j = i; j > 0; j -= (j&-j)) {//所有下级
            res += bit[j];
        }
        return res;
    }
    
    vector<int> vec; //具体的数据值,当前值
    vector<int> bit; //该数据对应的bit值
};
//一个数的上级index 是它的index + 最低位1 => j += (j&-j) 
//i & (-i) : [0110] -i = 1001 + 1 = 1010 so it is 10 = 2
//https://acm.sjtu.edu.cn/w/images/9/90/%E6%A0%91%E7%8A%B6%E6%95%B0%E7%BB%84.pdf
-i 是在 i 的基础上把二进制的符号位变化，并且其他位取反
然后+1，&是位运算，a & b 的算法就是把a,b的二进制形
式右对齐，然后如果全是1，这位还是1，否则为0
-6 -> 2  • i 和 -i 实际上除了i的最后一个1那位，其他位置都不一样，
所以我们得到了i的二进制下最右边的那个1
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
