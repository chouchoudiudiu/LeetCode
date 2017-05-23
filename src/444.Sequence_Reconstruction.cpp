class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if (seqs.empty())
            return false;
        int n = org.size(), toVerify = n - 1;
        vector<int> pos(n + 1, 0);
        vector<bool> verified(n + 1, false);
        for (int i = 0; i < n; ++i)
            pos[org[i]] = i; //org[i] can reach n
        bool existed = false;
        for (auto seq : seqs) 
            for (int i = 0; i < seq.size(); ++i) {
                existed = true;
                if (seq[i] <= 0 || seq[i] > n)
                    return false;
                if (i == 0)
                    continue;
                int pre = seq[i - 1], cur = seq[i];
                if (pos[pre] >= pos[cur])
                    return false;
                if (verified[cur] == false && pos[pre] + 1 == pos[cur]) {
                    verified[cur] = true;
                    --toVerify;
                }//only consecutive
            }

        return toVerify == 0 && existed;
    }
};

/*
false
[1]
[[],[]]

true
[1]
[[1]]
*/
