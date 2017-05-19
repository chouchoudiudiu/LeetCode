class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> tokens;
        istringstream in(preorder);
        string val;
        while (getline(in, val, ',')) 
            tokens.push_back(val);
        int diff = 1;
        for(auto t : tokens) {
            if (--diff < 0)
                return false;
            if (t != "#")
                diff += 2;
        }
        return diff == 0;
    }
};

/*
假设我们在根据先序遍历结果建立这棵树。建立过程中，用变量diff记录总的出度与入度之差(diff=outdegree-indegree)。读入下一个节点时，将diff减一，因为该节点具有一个入度。如果该节点非空，那么将diff加二，因为该节点具有两个出度。如果该先序序列是正确的话，那么diff不可能为负且结果应该为0.
在二叉树中，如果把空节点也当做叶子节点考虑的话，有如下性质：
除根节点外，所有非空节点有2个出度和1个入度（2个子节点，1个父节点）
所有空节点有0个出度和1个入度（0个子节点，1个父节点）
*/
