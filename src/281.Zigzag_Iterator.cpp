class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int n1 = v1.size(), n2 = v2.size(), j = 0;
        while (j < n1 || j < n2) {
            if (j < n1) v.push_back(v1[j]);
            if (j < n2) v.push_back(v2[j]);
            ++j;
        }
    }

    int next() {
        return v[i++];
    }

    bool hasNext() {
        return i < v.size();
    }
    vector<int> v; //combined
    int i = 0;
};
//Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?
//queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(!v1.empty())
            q.push({v1.begin(), v1.end()});
        if(!v2.empty())
            q.push({v2.begin(), v2.end()});
    }

    int next() {
        auto it = q.front().first, end = q.front().second;
        q.pop();
        if(it + 1 != end)
            q.push({it + 1, end});
        return *it;
    }

    bool hasNext() {
        return !q.empty();
    }
    
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
};
/*
由于题目中的Follow up让我们考虑将输入换成k个数组的情况，那么上面两种解法显然就不适用了，所以我们需要一种通解。我们可以采用queue加iterator的方法，用一个queue里面保存iterator的pair，在初始化的时候，有几个数组就生成几个pair放到queue中，每个pair保存该数组的首位置和尾位置的iterator，在next()函数中，我们取出queue队首的一个pair，如果当前的iterator不等于end()，我们将其下一个位置的iterator和end存入队尾，然后返回当前位置的值。
*/
/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
