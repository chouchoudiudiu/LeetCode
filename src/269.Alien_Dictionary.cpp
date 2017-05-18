class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_set<char> chars; //number of all unique chars
        set<pair<char, char>> edges; //better than vector here since there might be duplicate pairs during construction
        vector<int> indegree(256, 0);
        queue<char> q;//for topological sort
        for (auto word : words)
            for (auto c : word)
                chars.insert(c); //or chars.insert(word.begin(), word.end()) to replace these two lines
        //construct edges
        for (int i = 0; i < words.size() - 1; ++i) {
            int size = min(words[i].size(), words[i + 1].size());
            int j = 0;
            for (; j < size; ++j) {
                if (words[i][j] != words[i + 1][j]) {//[f, s]; insert like [s, f] means a should appear earlier
                    edges.insert(make_pair(words[i + 1][j], words[i][j]));
                    break;//go to find next edge
                }
            }
            if (j == size && words[i].size() > words[i + 1].size()) 
                return ""; //words[i].size() shorter is okay
        }
        //topological sort
        for (auto e : edges) {
            ++indegree[e.first];
        }
        for (auto c : chars) {
            if (indegree[c] == 0)
                q.push(c);
        }
        //int cnt = 0;//totoal count of vertex visited during BFS, not needed, use res.size()
        string res = "";
        while (!q.empty()) {
            char u = q.front();
            q.pop();
            res += u;
            for (auto v : edges) {
                if (v.second == u) {//v.first rely on u
                    if(--indegree[v.first] == 0)
                        q.push(v.first);
                }
            }
        }
        
        return res.size() == chars.size() ? res : ""; //cycle?
    }
};


//1. ["wrtkj","wrt"]..""
//2. ["wrt","wrtkj"].."jkrtw"
//["za","zb","ca","cb"].."abzc"
