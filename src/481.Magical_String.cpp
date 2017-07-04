class Solution {
public:
    int magicalString(int n) {
        vector<int> a(n + 2, 0); //j < n ++j, ++j
        a[0] = 1; 
        a[1] = 2; 
        a[2] = 2;
        for (int i = 2, j = 2; j < n; ++i) {//i in old seq, j in new seq; j is faster
            int nextVal = 3 - a[j]; //j: last index
            a[++j] = nextVal;
            if (a[i] == 2)
                a[++j] = nextVal;
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1)
                ++res;
        }
        return res;
    }
};
/*
http://bookshadow.com/weblog/2017/01/08/leetcode-magical-string/
令魔法字符串ms = '122'，维护指针p，初始令p = 2
若ms[p] == '1' 则向ms追加1个与ms末尾元素不同的字符
否则，向ms追加2个与ms末尾元素不同的字符
*/
