class Solution {
public:
//standard union find + root compression
    int root(int i) {
        while (i != id[i]) {
            id[i] = id[id[i]]; //make every other node in path point to its grandparent, trees stay very flat
            i = id[i];
        }
        return i;
    }
    bool find(int p, int q) { //check if p and q have the same root
        return root(p) == root(q);
    }
    void unite(int p, int q) {  //change root of p to point to root of q
        int i = root(p);
        int j = root(q);
        id[i] = j;
    }
    int countComponents(int n, vector<pair<int, int>>& edges) {
        for (int i = 0; i < n; ++i)
            id.push_back(i);
        for (auto e : edges) {
            int p = e.first;
            int q = e.second;
            if (!find(p, q)) {
                unite(p, q);
                --n;
            }
        }
        return n;
    }
    vector<int> id;
};
