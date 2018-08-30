class Solution {
public:
    int hammingWeight(int n) { //O(m) - m is the count of 1s
        int cnt = 0;
        while(n) {
            n &= n - 1;
            ++cnt;
        }
        return cnt;
    }
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        for (int i = 0; i <= num; ++i)
            res[i] = hammingWeight(i);
        return res;
    }
};


////////////////////////////////////////////
class Solution {
public:
// [2-3], [4-7], [8-15] 2-3是1 后面加0/1, 4-7是2-3后面加0/1, 8-15是4-7后面加0/1。。。。其实没用。。。直接看去掉最右边1后数有几个零，加上1
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for (int i = 1; i <= num; ++i)
            res[i] = res[i&(i - 1)] + 1;
        return res;
    }
};
//
 vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        res[1] = 1;
        for(int i = 2; i <= num; ++i) {
            res[i] = res[i>>1] + i%2
        }
        return res;
    }
