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
